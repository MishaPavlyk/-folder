text = input("Enter a string: ")
word = input("Enter the word to search for: ")

count = text.lower().split().count(word.lower())

print(f"The word '{word}' appears {count} times in the string.")
