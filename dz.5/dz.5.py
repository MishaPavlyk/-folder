try:
    input_filename = 'source.txt'

    target_word = input("Введіть слово для пошуку: ").strip()

    if not target_word:
        print("Слово для пошуку не введено.")
    else:
        with open(input_filename, 'r', encoding='utf-8') as file:
            content = file.read()

        words = content.split()
        word_count = sum(1 for word in words if word.strip('.,!?":;').lower() == target_word.lower())

        print(f"Слово '{target_word}' зустрічається {word_count} разів у файлі.")

except FileNotFoundError:
    print(f"Файл '{input_filename}' не знайдено.")
except Exception as e:
    print(f"Виникла помилка: {e}")
