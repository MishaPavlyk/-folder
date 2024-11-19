numbers = list(map(int, input("Enter a list of integers separated by spaces: ").split()))

min_value = min(numbers)
max_value = max(numbers)

negative_count = sum(1 for num in numbers if num < 0)
positive_count = sum(1 for num in numbers if num > 0)
zero_count = numbers.count(0)

print(f"Your list: {numbers}")
print(f"Minimum value: {min_value}")
print(f"Maximum value: {max_value}")
print(f"Number of negative elements: {negative_count}")
print(f"Number of positive elements: {positive_count}")
print(f"Number of zeros: {zero_count}")
