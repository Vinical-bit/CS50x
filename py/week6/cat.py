import time

def meow(n):
    for i in range(n):
        print("meow")
        time.sleep(0.6)  # espera 0.6 segundos antes de imprimir o próximo "meow"

n = int(input("how many times do you want me to meow? "))
meow(n)