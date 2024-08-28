'''
Question 4. Write a program that reads two integers - hours and minutes based on a 
24-hour day format and calculates what time it will be 15 minutes later. 
The result should be printed in the following format hh:mm. 
Hours should always be between 0 and 23, while minutes should always be between 0 
and 59. Hours should be written with one or two digits as needed, while the minutes 
should always be written with two digits - add a leading zero, as needed. 
Example, Given the time 1:46 as input, the output displayed should be 2:01. 
'''
# Read hours and minutes as input
hours = int(input("Enter hours: "))
minutes = int(input("Enter minutes: "))

# Add 15 minutes
minutes += 15

# If minutes exceed 59, adjust the hours and minutes
if minutes >= 60:
    minutes -= 60
    hours += 1

# If hours exceed 23, reset to 0
if hours >= 24:
    hours = 0

# Print the result with proper formatting
print(f"{hours}:{minutes:02d}")