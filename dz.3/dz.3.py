try:
    input_filename = 'source.txt'
    output_filename = 'destination.txt'

    with open(input_filename, 'r') as input_file:
        lines = input_file.readlines()

    lines.reverse()


    with open(output_filename, 'w') as output_file:
        output_file.writelines(lines)

    print(f"Рядки успішно переписано до файлу '{output_filename}'.")

except FileNotFoundError:
    print(f"Файл '{input_filename}' не знайдено.")
except Exception as e:
    print(f"Виникла помилка: {e}")
