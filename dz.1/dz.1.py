try:
    input_filename1 = 'file1.txt'
    input_filename2 = 'file2.txt'

    with open(input_filename1, 'r') as file1, open(input_filename2, 'r') as file2:
        lines1 = file1.readlines()
        lines2 = file2.readlines()

    max_lines = max(len(lines1), len(lines2))
    differences_found = False

    for i in range(max_lines):
        line1 = lines1[i].strip() if i < len(lines1) else "(рядка немає у файлі)"
        line2 = lines2[i].strip() if i < len(lines2) else "(рядка немає у файлі)"

        if line1 != line2:
            differences_found = True
            print(f"Рядок {i + 1} не збігається:")
            print(f"  У {input_filename1}: {line1}")
            print(f"  У {input_filename2}: {line2}")

    if not differences_found:
        print("Всі рядки у файлах збігаються.")
    else:
        print("Перевірка завершена: знайдено відмінності.")

except FileNotFoundError as e:
    print(f"Файл не знайдено: {e.filename}")
except Exception as e:
    print(f"Виникла помилка: {e}")
