import random

def multiplication_test(level, questions):
    correct_answers = 0

    for _ in range(questions):
        if level == 1:
            num1, num2 = random.randint(1, 5), random.randint(1, 5)
        elif level == 2:
            num1, num2 = random.randint(1, 10), random.randint(1, 10)
        elif level == 3:
            num1, num2 = random.randint(1, 15), random.randint(1, 15)
        user_answer = int(input(f"Скільки буде {num1} * {num2}? "))

        if user_answer == num1 * num2:
            print("Правильно!")
            correct_answers += 1
        else:
            print(f"Неправильно. Правильний відповідь: {num1 * num2}")

    print(f"\nВи дали {correct_answers} правильних відповідей з {questions}.")
    percentage = (correct_answers / questions) * 100
    if percentage == 100:
        print("Відмінно!")
    elif percentage >= 75:
        print("Добре!")
    elif percentage >= 50:
        print("Задовільно.")
    else:
        print("Не задовільно. Треба ще попрактикуватися.")


print("Виберіть рівень складності:")
print("1. Легкий (числа від 1 до 5)")
print("2. Середній (числа від 1 до 10)")
print("3. Важкий (числа від 1 до 15)")

level = int(input("Введіть номер рівня (1-3): "))
questions = int(input("Скільки запитань ви хочете відповісти? "))

multiplication_test(level, questions)