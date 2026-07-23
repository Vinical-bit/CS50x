i = 0
digit = 0
mult = 0
rest = 0

num = int(input("Number: "))
orig = num
while num > 0:
    i += 1
    digit = num % 10
    if i % 2 == 0:
        digit = digit * 2
        if digit > 9:
            mult += (digit//10) + (digit % 10) # o // divide sem deixar resto 
        else:
            mult += digit
    else:
        rest += digit
    num = num//10


total = mult + rest

if total % 10 == 0:
    # amex
    s = str(orig)
    if len(str(orig)) == 15 and (s[0:2] == "34" or s[0:2] == "37"): # o str(orig) transforma o número em string para poder pegar os dois primeiros dígitos s[0:2] serve para pegar os dois primeiros dígitos da string
        print("AMEX")

    # mastercard
    elif len(str(orig)) == 16 and (int(s[0:2]) >= 51 and int(s[0:2]) <= 55):
        print("MASTERCARD")

    # visa
    elif (len(str(orig)) == 13 or len(str(orig)) == 16) and s[0:1] == "4":
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
