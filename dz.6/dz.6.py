try:
    input_filename = 'source.txt'
    output_filename = 'destination.txt'

    with open(input_filename, 'r') as input_file:
        lines = input_file.readlines()

    with open(output_filename, 'w') as output_file:
        for line in lines:
            modified_line = line.replace('*', '#').replace('&', '*').replace('#', '&')
            output_file.write(modified_line)

    print(f"Рядки успішно переписано до файлу '{output_filename}'.")

except FileNotFoundError:
    print(f"Файл '{input_filename}' не знайдено.")
except Exception as e:
    print(f"Виникла помилка: {e}")
