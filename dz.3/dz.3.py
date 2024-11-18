start = int(input("Введіть початок діапазону: "))
end = int(input("Введіть кінець діапазону: "))

for i in range(start, end + 1):
    for j in range(1, 11):
        print(f"{i} * {j} = {i * j}", end="\t")
    print()