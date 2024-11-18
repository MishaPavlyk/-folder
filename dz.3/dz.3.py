def draw_square(size, symbol, filled):
    if size < 2:
        print("Розмір квадрата має бути не менше 2.")
        return

    for row in range(size):
        if filled or row == 0 or row == size - 1:
            print(symbol * size)
        else:
            print(symbol + " " * (size - 2) + symbol)

size = int(input("Введіть розмір квадрата: "))
symbol = input("Введіть символ для малювання: ")
filled_input = input("Чи буде квадрат заповнений? (так/ні): ").strip().lower()

filled = filled_input == "так"

draw_square(size, symbol, filled)
