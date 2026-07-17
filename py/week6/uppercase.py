before = input("Before: ")
print("After: ", end="")
for c in before:
    print(c.upper(), end="") # o end ="" serve para não quebrar a linha e imprimir tudo na mesma linha
print() # imprime uma nova linha no final para que o prompt do terminal não fique na mesma linha da saída