try:
    input_filename = 'source.txt'
    user_char = input("Введіть символ для пошуку: ")

    with open(input_filename, 'r') as input_file:
        lines = input_file.readlines()

    word_count = 0

    for line in lines:
        words = line.split()
        for word in words:
            if word.startswith(user_char):
                word_count += 1

    print(f"Кількість слів, що починаються з '{user_char}': {word_count}.")

except FileNotFoundError:
    print(f"Файл '{input_filename}' не знайдено.")
except Exception as e:
    print(f"Виникла помилка: {e}")
