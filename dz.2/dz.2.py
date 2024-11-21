try:
    input_filename = 'input.txt'
    output_filename = 'statistics.txt'

    with open(input_filename, 'r', encoding='utf-8') as file:
        content = file.read()

    num_chars = len(content)
    num_lines = content.count('\n') + 1 if content else 0  # Кількість рядків
    vowels = 'aeiouAEIOUаеиоуюяіїєАЕИОУЮЯІЇЄ'
    consonants = (
        'bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ'
        'бвгґджзйклмнпрстфхцчшщБВГҐДЖЗЙКЛМНПРСТФХЦЧШЩ'
    )
    num_vowels = sum(1 for char in content if char in vowels)
    num_consonants = sum(1 for char in content if char in consonants)
    num_digits = sum(1 for char in content if char.isdigit())

    stats = (
        f"Кількість символів: {num_chars}\n"
        f"Кількість рядків: {num_lines}\n"
        f"Кількість голосних літер: {num_vowels}\n"
        f"Кількість приголосних літер: {num_consonants}\n"
        f"Кількість цифр: {num_digits}\n"
    )

    with open(output_filename, 'w', encoding='utf-8') as output_file:
        output_file.write(stats)

    print(f"Статистика записана до файлу '{output_filename}'.")

except FileNotFoundError:
    print(f"Файл '{input_filename}' не знайдено.")
except Exception as e:
    print(f"Виникла помилка: {e}")
