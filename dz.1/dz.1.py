try:
    input_filename = 'test.txt'
    output_filename = 'filtered_words.txt'

    with open(input_filename, 'r') as file:
        content = file.read()

    words = content.split()
    long_words = [word for word in words if len(word) >= 7]

    with open(output_filename, 'w') as output_file:
        output_file.write('\n'.join(long_words))

    print(f"Слова записано до файлу '{output_filename}'.")

except FileNotFoundError:
    print(f"Файл '{input_filename}' не знайдено.")
except Exception as e:
    print(f"Виникла помилка: {e}")
