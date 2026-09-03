import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # pegar o total de shares do user logado
    rows = db.execute("SELECT symbol, sum(CASE WHEN type='buy' THEN shares ELSE -shares END) AS total_share FROM transactions WHERE user_id = ? GROUP BY symbol HAVING total_share > 0", session["user_id"]) # o having total_share > 0 é para pegar apenas as ações que o user tem, ou seja, que não foram vendidas

    # calcular o preço atual e o valor total de cada ação
    for row in rows:
        var = lookup(row["symbol"])
        row["price"] = var["price"]
        row["total_value"] = row["total_share"] * row["price"]

    # pegar o cash do user
    user_row = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"]) # aqui pega o id do user logado
    cash = user_row[0]["cash"] # pega o cash do user logado
    # calcular o total geral
    grand_total = sum(row["total_value"] for row in rows) + cash

    return render_template("index.html", rows=rows, cash=cash, grand_total=grand_total)

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        """ pegar o symbol e quantidade do form"""
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        # verificar se é valido
        if not symbol or not shares:
            return apology("must provide symbol and quantity")
        try:
            shares = int(shares) 
        except ValueError:
            return apology("must provide quantity")

        if shares <= 0:
            return apology("must provide one integer number")
        
        # consultar preço com lookup
        result = lookup(symbol)
        if result is None:
            return apology("not found")
        
        price = result["price"]

        # pegar o cash do user
        rows = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"]) # aqui pega o id do user logado
        cash = rows[0]["cash"] # pega o cash do user logado

        # verificar se tem dinheiro suficiente
        if cash < price * shares:
            return apology("insufficient funds")
        # se sim atualizar tabela de users e transactions
        else:
            db.execute("UPDATE users SET cash = ? WHERE id = ?", cash - price * shares, session["user_id"])

            db.execute("INSERT INTO transactions (user_id, symbol, shares, price, transacted_at, type) VALUES(?, ?, ?, ?, ?, ?)", session["user_id"], symbol, shares, price, datetime.now(), "buy")
            return redirect("/")
    else:
        return render_template("buy.html")
        

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    rows = db.execute("SELECT * FROM transactions WHERE user_id = ? ORDER BY transacted_at DESC", session["user_id"])
    return render_template("history.html", rows=rows)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("must provide symbol")

        result = lookup(symbol)
        if result is None:
            return apology("not found")
        return render_template("quote.html", symbol= result["symbol"], name= result["name"], price=result["price"])
        
    else:    
        return render_template("quote.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        if not username:
            return apology("must provide username")

        password = request.form.get("password")
        if not password:
            return apology("must provide password")
        
        confirmation = request.form.get("confirmation")
        if not confirmation:
            return apology("must provide confirmation")
        
        if(password != confirmation):
            return apology("different password")
        
        hashpin = generate_password_hash(password)
        
        try:
            db.execute("INSERT INTO users (username,hash) VALUES(?,?)", username, hashpin)
        except ValueError:
            return apology("Same username")

        return redirect("/login")
    else:
        return render_template("register.html")



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        if not symbol or not shares:
            return apology("must provide symbol and shares",)
        
        try:
            shares = int(shares)
        except ValueError:
            return apology("must provide quantity",)

        if shares <= 0:
            return apology("must provide one integer number",)
        
        # consultar preço com lookup
        result = lookup(symbol)
        if result is None:
            return apology("not found")
        
        rows = db.execute("SELECT symbol, sum(CASE WHEN type='buy' THEN shares ELSE -shares END) AS total_share FROM transactions WHERE user_id = ? AND symbol = ? GROUP BY symbol HAVING total_share > 0", session["user_id"], symbol)
        # verificar se o user tem ações suficientes para vender/ o length do rows é 1 se o user tiver ações, se não tiver será 0, e se tiver menos ações do que quer vender, o total_share será menor do que shares    
        if len(rows) != 1 or rows[0]["total_share"] < shares:
            return apology("not enough shares")
        
        price = result["price"]
        # pegar o cash do user
        rows = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"]) # aqui pega o id do user logado
        cash = rows[0]["cash"] # pega o cash do user logado
        # atualizar tabela de users e transactions
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash + price * shares, session["user_id"])
        # registrar a transação na tabela transactions
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, transacted_at, type) VALUES(?, ?, ?, ?, ?, ?)", session["user_id"], symbol, shares, price, datetime.now(), "sell")
        return redirect("/")
    else:
        # pegar o total de shares do user logado
        return render_template("sell.html", rows=db.execute("SELECT symbol, sum(CASE WHEN type='buy' THEN shares ELSE -shares END) AS total_share FROM transactions WHERE user_id = ? GROUP BY symbol HAVING total_share > 0", session["user_id"]))