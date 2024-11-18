def count_digits(number):
    return len(number)


def sum_digits(number):
    return sum(int(digit) for digit in number)


def average_digits(number):
    total_sum = sum_digits(number)
    return total_sum / len(number)


def count_zeros(number):
    return number.count("0")


user_number = None

while True:
    print("\nМеню:")
    print("1. Ввести число")
    print("2. Порахувати кількість цифр")
    print("3. Порахувати суму цифр")
    print("4. Порахувати середнє арифметичне цифр")
    print("5. Порахувати кількість нулів")
    print("6. Вихід")

    choice = input("Виберіть опцію (1-6): ")

    if choice == "1":
        user_number = input("Введіть число: ")
        print(f"Ви ввели число: {user_number}")

    elif choice == "2":
        if user_number is not None:
            print(f"Кількість цифр у числі {user_number}: {count_digits(user_number)}")
        else:
            print("Спочатку введіть число (опція 1).")

    elif choice == "3":
        if user_number is not None:
            print(f"Сума цифр у числі {user_number}: {sum_digits(user_number)}")
        else:
            print("Спочатку введіть число (опція 1).")

    elif choice == "4":
        if user_number is not None:
            print(f"Середнє арифметичне цифр у числі {user_number}: {average_digits(user_number):.2f}")
        else:
            print("Спочатку введіть число (опція 1).")

    elif choice == "5":
        if user_number is not None:
            print(f"Кількість нулів у числі {user_number}: {count_zeros(user_number)}")
        else:
            print("Спочатку введіть число (опція 1).")

    elif choice == "6":
        print("Вихід з програми.")
        break

    else:
        print("Неправильний вибір, спробуйте ще раз.")

def print_chess_board(cell_size, board_size=8):
    for row in range(board_size):
        for i in range(cell_size):
            for col in range(board_size):
                if (row + col) % 2 == 0:
                    print("*" * cell_size, end="")
                else:
                    print("-" * cell_size, end="")
            print()


cell_size = int(input("Введіть розмір клітинки: "))
print_chess_board(cell_size)