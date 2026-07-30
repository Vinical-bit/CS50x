import csv

with open("favorites.csv", "r") as file:
    reader = csv.reader(file)
    next(reader)

    # scratch, c, python = 0, 0, 0

    # for row in reader:
    #     favorite = row["language"]
    #     if favorite == "Scratch":
    #         scratch+= 1
    #     elif favorite == "C":
    #         c +=1
    #     elif favorite == "Python":
    #         python += 1
# print(f"Scratch: {scratch}")
# print(f"C: {c}")
# print(f"Python: {python}")

    count = {}

    # for row in reader:
    #     favorite = row["language"]
    #     if favorite in count:
    #         count[favorite] += 1

    for row in reader:
        favorite = row["language"]
        try:
            count[favorite] +=1
        except KeyError:
            count[favorite] = 1


for favorite in count:
    print(favorite, count[favorite])
