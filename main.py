# def count_digits(number):
#     return len(number)
#
#
# def sum_digits(number):
#     return sum(int(digit) for digit in number)
#
#
# def average_digits(number):
#     total_sum = sum_digits(number)
#     return total_sum / len(number)
#
#
# def count_zeros(number):
#     return number.count("0")
#
#
# user_number = None
#
# while True:
#     print("\nМеню:")
#     print("1. Ввести число")
#     print("2. Порахувати кількість цифр")
#     print("3. Порахувати суму цифр")
#     print("4. Порахувати середнє арифметичне цифр")
#     print("5. Порахувати кількість нулів")
#     print("6. Вихід")
#
#     choice = input("Виберіть опцію (1-6): ")
#
#     if choice == "1":
#         user_number = input("Введіть число: ")
#         print(f"Ви ввели число: {user_number}")
#
#     elif choice == "2":
#         if user_number is not None:
#             print(f"Кількість цифр у числі {user_number}: {count_digits(user_number)}")
#         else:
#             print("Спочатку введіть число (опція 1).")
#
#     elif choice == "3":
#         if user_number is not None:
#             print(f"Сума цифр у числі {user_number}: {sum_digits(user_number)}")
#         else:
#             print("Спочатку введіть число (опція 1).")
#
#     elif choice == "4":
#         if user_number is not None:
#             print(f"Середнє арифметичне цифр у числі {user_number}: {average_digits(user_number):.2f}")
#         else:
#             print("Спочатку введіть число (опція 1).")
#
#     elif choice == "5":
#         if user_number is not None:
#             print(f"Кількість нулів у числі {user_number}: {count_zeros(user_number)}")
#         else:
#             print("Спочатку введіть число (опція 1).")
#
#     elif choice == "6":
#         print("Вихід з програми.")
#         break
#
#     else:
#         print("Неправильний вибір, спробуйте ще раз.")

# def print_chess_board(cell_size, board_size=8):
#     for row in range(board_size):
#         for i in range(cell_size):
#             for col in range(board_size):
#                 if (row + col) % 2 == 0:
#                     print("*" * cell_size, end="")
#                 else:
#                     print("-" * cell_size, end="")
#             print()
#
#
# cell_size = int(input("Введіть розмір клітинки: "))
# print_chess_board(cell_size)


# import random
#
# def multiplication_test(level, questions):
#     correct_answers = 0
#
#     for _ in range(questions):
#         if level == 1:
#             num1, num2 = random.randint(1, 5), random.randint(1, 5)
#         elif level == 2:
#             num1, num2 = random.randint(1, 10), random.randint(1, 10)
#         elif level == 3:
#             num1, num2 = random.randint(1, 15), random.randint(1, 15)
#         user_answer = int(input(f"Скільки буде {num1} * {num2}? "))
#
#         if user_answer == num1 * num2:
#             print("Правильно!")
#             correct_answers += 1
#         else:
#             print(f"Неправильно. Правильний відповідь: {num1 * num2}")
#
#     print(f"\nВи дали {correct_answers} правильних відповідей з {questions}.")
#     percentage = (correct_answers / questions) * 100
#     if percentage == 100:
#         print("Відмінно!")
#     elif percentage >= 75:
#         print("Добре!")
#     elif percentage >= 50:
#         print("Задовільно.")
#     else:
#         print("Не задовільно. Треба ще попрактикуватися.")
#
#
# print("Виберіть рівень складності:")
# print("1. Легкий (числа від 1 до 5)")
# print("2. Середній (числа від 1 до 10)")
# print("3. Важкий (числа від 1 до 15)")
#
# level = int(input("Введіть номер рівня (1-3): "))
# questions = int(input("Скільки запитань ви хочете відповісти? "))
#
# multiplication_test(level, questions)


def print_diamond(size):
    for i in range(size):
        print(" " * (size - i - 1) + "*" * (2 * i + 1))

    for i in range(size - 2, -1, -1):
        print(" " * (size - i - 1) + "*" * (2 * i + 1))


size = int(input("Введіть розмір ромба (позитивне ціле число): "))
print_diamond(size)
