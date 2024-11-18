def count_digits(number):
    return len(str(abs(number)))

number = int(input("Введіть число: "))

result = count_digits(number)
print(f"Кількість цифр у числі {number}: {result}")
