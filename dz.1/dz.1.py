def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

start = int(input("Введіть початок діапазону: "))
end = int(input("Введіть кінець діапазону: "))

print(f"Прості числа в діапазоні від {start} до {end}:")
for num in range(start, end + 1):
    if is_prime(num):
        print(num)
