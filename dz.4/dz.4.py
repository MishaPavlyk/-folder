try:
    input_filename = 'source.txt'

    with open(input_filename, 'r', encoding='utf-8') as file:
        lines = file.readlines()

    max_length = max(len(line.strip()) for line in lines) if lines else 0

    print(f"Довжина найдовшого рядка: {max_length}")

except FileNotFoundError:
    print(f"Файл '{input_filename}' не знайдено.")
except Exception as e:
    print(f"Виникла помилка: {e}")
