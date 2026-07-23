
# pegar o numero de 1 a 8

while True:
    n = int(input("Height: "))
    if (n >= 1 and n <= 8):
        break

for i in range(n):
    right = "#" * (i + 1)
    left = "#" * (i + 1)
    line = left + "  " + right