score = []
for i in range(3):
    score.append(int(input(f"score {i+1} ")))

average = sum(score) / len(score)

print(f"{average:.2f}")