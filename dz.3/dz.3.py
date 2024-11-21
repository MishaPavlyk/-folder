try:
    input_filename = 'input.txt'
    output_filename = 'output.txt'

    with open(input_filename, 'r', encoding='utf-8') as file:
        lines = file.readlines()

    if lines:
        lines = lines[:-1]

    with open(output_filename, 'w', encoding='utf-8') as output_file:
        output_file.writelines(lines)

    print(f"Файл без останнього рядка записано до '{output_filename}'.")

except FileNotFoundError:
    print(f"Файл '{input_filename}' не знайдено.")
except Exception as e:
    print(f"Виникла помилка: {e}")
