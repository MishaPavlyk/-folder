def is_palindrome(number):
    num_str = str(abs(number))

    length = len(num_str)

    if length % 2 == 0:
        first_half = num_str[:length // 2]
        second_half = num_str[length // 2:]
    else:
        first_half = num_str[:length // 2]
        second_half = num_str[length // 2 + 1:]

    return first_half == second_half[::-1]


number = int(input("Введіть число: "))

if is_palindrome(number):
    print(f"Число {number} є паліндромом.")
else:
    print(f"Число {number} не є паліндромом.")
