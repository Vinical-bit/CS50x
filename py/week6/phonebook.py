names =["Vinical", "David", "Jhon"]

name = input("Nmae: ")

for n in names:
    if name.lower() == n.lower():
        print("Found")
        break
else:
    print("Not found")

print("------------------------")

names =["Vinical", "Davi", "Gabriel"]

name = input("Nmae: ")

if name in names:
    print("Found")
else:
    print("Not found")
print("-----------------------")

phone = {
    "Vinical": "123-456-7890",
    "David": "987-654-3210",    
    "Jhon": "555-555-5555"
}

nome = input("nome:")

if nome in [n.lower() for n in phone.keys()]: # verifica se o nome digitado está presente nas chaves do dicionário, ignorando a diferença entre maiúsculas e minúsculas 
    number = phone[nome.capitalize()]  # o capitalize() é usado para garantir que a primeira letra do nome esteja em maiúscula, pois as chaves do dicionário estão com a primeira letra maiúscula
    print(f"Number: {number}")
    print("Found")
else:
    print("Not found")

