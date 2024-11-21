try:
    input_filename = 'source.txt'
    output_filename = 'destination.txt'

    with open(input_filename, 'r') as input_file:
        lines = input_file.readlines()

    found_line_without_comma = False

    for i in range(len(lines)):
        if ',' not in lines[i]:
            lines.insert(i + 1, '************\n')
            found_line_without_comma = True
            break

    if not found_line_without_comma:
        lines.append('************\n')

    with open(output_filename, 'w') as output_file:
        output_file.writelines(lines)

    print(f"Результат успішно записано до файлу '{output_filename}'.")

except FileNotFoundError:
    print(f"Файл '{input_filename}' не знайдено.")
except Exception as e:
    print(f"Виникла помилка: {e}")
