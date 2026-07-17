while True:
    n = int(input("Height: "))
    if n > 0:
        break
for i in range(n):
    print("#")

for i in range(4):
    print("?", end = "")
print()

print("?" * n)
