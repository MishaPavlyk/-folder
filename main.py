#Завдання 1
# def is_prime(num):
#     if num < 2:
#         return False
#     for i in range(2, int(num**0.5) + 1):
#         if num % i == 0:
#             return False
#     return True
#
# start = int(input("Введіть початок діапазону: "))
# end = int(input("Введіть кінець діапазону: "))
#
# print(f"Прості числа в діапазоні від {start} до {end}:")
# for num in range(start, end + 1):
#     if is_prime(num):
#         print(num)

#Завдання 2
# for i in range(1, 11):
#     for j in range(1, 11):
#         print(f"{i} * {j} = {i * j}", end="\t")
#     print()


#Завдання 3
# start = int(input("Введіть початок діапазону: "))
# end = int(input("Введіть кінець діапазону: "))
#
# for i in range(start, end + 1):
#     for j in range(1, 11):
#         print(f"{i} * {j} = {i * j}", end="\t")
#     print()
