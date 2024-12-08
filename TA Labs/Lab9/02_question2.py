'''
Question 2. Use list comprehensions for the following.
    1. Take a list of strings as input along with a sample string. Count the number of strings that 
        contains the sample string as a substring. 
    2. Take a list of integers as input. Find the square of only the +ve integers in the list, the rest 
        are converted to 0s. 
    3. Take a list of integers as input. Find the square of numbers that are in the range of 10-20, 
        leave the rest as they are in the resultant list.
    4. Take a list of strings as input, convert all the strings into upper case, if they have the first 
        character as lower case, leave the rest as they are.
'''
#A part
input_list = input("Enter a list of strings (space-separated): ").split(' ')
sample_string = input("Enter the sample string: ")

count = sum([1 for s in input_list if sample_string in s])

print("Number of strings containing the sample string:", count)

#B part
input_list = list(map(int, input("Enter a list of integers (space-separated): ").split()))

result = [x**2 if x > 0 else 0 for x in input_list]

print("List with squared positive integers and 0s for others:", result)

#C part
input_list = list(map(int, input("Enter a list of integers (space-separated): ").split()))

result = [x**2 if 10 <= x <= 20 else x for x in input_list]

print("List with squared numbers in the range 10-20:", result)

#D part
input_list = input("Enter a list of strings (space-separated): ").split(' ')

result = [s.upper() if s[0].islower() else s for s in input_list]

print("List with specific strings converted to upper case:", result)