import random
def generate_random_array(length, min_value, max_value):
    # Generate the first random number
    random_array = [random.randint(min_value, max_value)]

    # Generate subsequent numbers, ensuring they are not the same as the previous one
    for _ in range(1, length):
        previous_number = random_array[-1]
        new_number = random.randint(min_value, max_value)

        # Make sure the new number is not the same as the previous one
        while new_number == previous_number:
            new_number = random.randint(min_value, max_value)

        random_array.append(new_number)

    return random_array

# Example: Generate a random array of length 10 with values between 1 and 100
print(generate_random_array(10, 1, 10))
print(generate_random_array(20, 1, 20))
print(generate_random_array(30, 1, 30))
print(generate_random_array(40, 1, 40))
print(generate_random_array(50, 1, 50))

# Data yang saya dapat
# •	10 Data [10, 7, 5, 1, 3, 5, 3, 8, 9, 6]
# •	20 Data [10, 5, 15, 20, 7, 2, 11, 1, 2, 8, 6, 20, 13, 6, 14, 5, 9, 7, 10, 13]
# •	30 Data [22, 9, 2, 14, 1, 24, 12, 6, 29, 5, 20, 23, 22, 29, 10, 21, 10, 21, 14, 10, 1, 27, 4, 18, 16, 1, 10, 5, 19, 23]
# •	40 Data [6, 26, 33, 38, 18, 1, 25, 29, 24, 16, 19, 34, 36, 13, 27, 21, 19, 33, 28, 22, 37, 9, 33, 1, 19, 17, 40, 35, 2, 25, 7, 31, 3, 21, 24, 6, 21, 19, 36, 21]
# •	50 Data [4, 43, 25, 3, 33, 35, 24, 12, 41, 2, 23, 50, 37, 29, 19, 9, 36, 18, 4, 45, 10, 9, 35, 15, 3, 36, 25, 39, 20, 2, 49, 14, 13, 41, 9, 29, 4, 41, 8, 7, 47, 37, 40, 3, 23, 22, 16, 41, 17, 49]
