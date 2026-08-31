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
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        """ pegar o symbol e quantidade do form"""
        symbol = request.form.get("symbol")
        quantity = request.form.get("quantity")

        # verificar se é valido
        if not symbol or not quantity:
            return apology("must provide symbol and quantity", 403)
        try:
            shares = int(quantity) 
        except ValueError:
            return apology("must provide quantity", 403)

        if shares <= 0:
            return apology("must provide one integer number", 403)
        
        # consultar preço com lookup
        result = lookup(symbol)
        if result is None:
            return apology("not found",403)
        
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
    return apology("TODO")


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
            return apology("must provide symbol", 403)

        result = lookup(symbol)
        if result is None:
            return apology("not found",403)
        return render_template("quote.html", symbol= result["symbol"], name= result["name"], price=result["price"])
        
    else:    
        return render_template("quote.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        if not username:
            return apology("must provide username", 403)

        password = request.form.get("password")
        if not password:
            return apology("must provide password", 403)
        
        confirmation = request.form.get("confirmation")
        if not confirmation:
            return apology("must provide confirmation", 403)
        
        if(password != confirmation):
            return apology("different password", 403)
        
        hashpin = generate_password_hash(password)
        
        try:
            db.execute("INSERT INTO users (username,hash) VALUES(?,?)", username, hashpin)
        except ValueError:
            return apology("Same username", 403)

        return redirect("/login")
    else:
        return render_template("register.html")



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
