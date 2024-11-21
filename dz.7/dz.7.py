try:
    lines = [
        "I have a best friend.",
        "Her name is Anna. Anna is very nice and funny.",
        "We go to the same school.",
        "Every day, we walk to school together.",
        "After school, we like to play games.",
        "Our favorite game is soccer.",
        "Anna is very good at soccer.",
        "Sometimes, we also watch movies.",
        "My favorite movie is «Toy Story».",
        "Anna likes it too. We always have fun together."
    ]

    output_filename = 'destination.txt'

    with open(output_filename, 'w', encoding='utf-8') as output_file:
        for line in lines:
            output_file.write(line + '\n')

    print(f"Рядки успішно записано до файлу '{output_filename}'.")

except FileNotFoundError:
    print(f"Файл '{output_filename}' не знайдено.")
except PermissionError:
    print(f"Помилка доступу до файлу '{output_filename}'. Перевірте права доступу.")
except Exception as e:
    print(f"Виникла помилка: {e}")
