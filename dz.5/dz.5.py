def product_in_range(start, end):
    lower = min(start, end)
    upper = max(start, end)

    product = 1

    for num in range(lower, upper + 1):
        product *= num

    return product


start = int(input("Введіть початкове число: "))
end = int(input("Введіть кінцеве число: "))

result = product_in_range(start, end)
print(f"Добуток чисел між {start} і {end}: {result}")
