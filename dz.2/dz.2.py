def display_even_numbers(start, end):
    lower = min(start, end)
    upper = max(start, end)

    print(f"Парні числа між {lower} і {upper}:")
    for num in range(lower, upper + 1):
        if num % 2 == 0:
            print(num, end=" ")
    print()

start = int(input("Введіть початкове число: "))
end = int(input("Введіть кінцеве число: "))

display_even_numbers(start, end)
