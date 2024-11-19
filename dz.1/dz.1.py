expression = input("Enter an arithmetic expression (e.g., 23 + 12): ")

try:
    result = eval(expression)
    print(f"The result of the expression {expression} is: {result}")
except (SyntaxError, NameError, ZeroDivisionError) as e:
    print("Invalid expression. Please enter a valid arithmetic expression.")
