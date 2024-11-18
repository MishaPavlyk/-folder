def find_minimum(a, b, c, d, e):
    return min(a, b, c, d, e)

a = int(input("Введіть перше число: "))
b = int(input("Введіть друге число: "))
c = int(input("Введіть третє число: "))
d = int(input("Введіть четверте число: "))
e = int(input("Введіть п'яте число: "))


result = find_minimum(a, b, c, d, e)
print("Мінімальне число:", result)
