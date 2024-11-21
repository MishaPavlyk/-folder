try:
    source_filename = 'source.txt'
    destination_filename = 'destination.txt'

    target_word = input("Введіть слово для пошуку: ").strip()
    replacement_word = input("Введіть слово для заміни: ").strip()

    if not target_word or not replacement_word:
        print("Пошукове або замінне слово не введено.")
    else:
        with open(source_filename, 'r', encoding='utf-8') as source_file:
            content = source_file.read()

        import re
        updated_content = re.sub(rf'\b{re.escape(target_word)}\b', replacement_word, content)

        with open(destination_filename, 'w', encoding='utf-8') as destination_file:
            destination_file.write(updated_content)

        print(f"Слово '{target_word}' замінено на '{replacement_word}' у файлі '{destination_filename}'.")

except FileNotFoundError:
    print(f"Файл '{source_filename}' не знайдено.")
except Exception as e:
    print(f"Виникла помилка: {e}")
