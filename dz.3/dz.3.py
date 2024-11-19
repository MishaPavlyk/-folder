user_input = input("Enter a string: ")
search_char = input("Enter a character to search for: ")
count = user_input.count(search_char)
print(f"The character '{search_char}' appears {count} times.")