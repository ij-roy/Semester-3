'''
Write a function that takes as input a string that stores date and time (24-hour clock) in the 
following format:
“MM/DD/YYYY HR:MIN:SEC” and prints the following:
• DD/MM/YYYY
• HR:MIN:SEC
• MM/YYYY
• Whether the time is “AM” or “PM”.
Validation of the input in the function is necessary. For example, if the user gives an input of 
“122/04/1990 13:12:12”, the given string is invalid, as there can be only 12 months in a year. Think 
of all possible erroneous inputs and write code to handle them. The function doesn’t return 
anything.
'''
def validate_and_print_datetime(date_time_str):
    parts = date_time_str.split()
    
    if len(parts) != 2:
        print("Invalid input: Please provide date and time in the format MM/DD/YYYY HR:MIN:SEC.")
        return

    date_part = parts[0]
    time_part = parts[1]
    
    # Validate the date part
    date_components = date_part.split('/')
    if len(date_components) != 3:
        print("Invalid input: Please provide date in the format MM/DD/YYYY.")
        return

    month = date_components[0]
    day = date_components[1]
    year = date_components[2]

    # Validate the time part
    time_components = time_part.split(':')
    if len(time_components) != 3:
        print("Invalid input: Please provide time in the format HR:MIN:SEC.")
        return

    hour = time_components[0]
    minute = time_components[1]
    second = time_components[2]

    # Check if all components are digits
    if not (month.isdigit() and day.isdigit() and year.isdigit() and hour.isdigit() and minute.isdigit() and second.isdigit()):
        print("Invalid input: Date and time must contain numeric values.")
        return

    # Convert string components to integers
    month = int(month)
    day = int(day)
    year = int(year)
    hour = int(hour)
    minute = int(minute)
    second = int(second)

    # Validate the date components
    if month < 1 or month > 12:
        print("Invalid input: Month must be between 1 and 12.")
        print(month)
        return
    if day < 1 or day > 31:
        print("Invalid input: Day must be between 1 and 31.")
        return
    if hour < 0 or hour > 23:
        print("Invalid input: Hour must be between 0 and 23.")
        return
    if minute < 0 or minute > 59:
        print("Invalid input: Minute must be between 0 and 59.")
        return
    if second < 0 or second > 59:
        print("Invalid input: Second must be between 0 and 59.")
        return

    # Adjust the day for months that have less than 31 days
    if month in [4, 6, 9, 11] and day > 30:
        print("Invalid input: Month has only 30 days.")
        return
    if month == 2:
        if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
            if day > 29:  # Leap year
                print("Invalid input: February has only 29 days in a leap year.")
                return
        else:
            if day > 28:  # Non-leap year
                print("Invalid input: February has only 28 days in a non-leap year.")
                return

    print(f"DD/MM/YYYY: {day:02}/{month:02}/{year}")
    print(f"HR:MIN:SEC: {hour:02}:{minute:02}:{second:02}")
    print(f"MM/YYYY: {month:02}/{year}")

    # Determine and print AM or PM
    if hour < 12:
        print("Time of day: AM")
    else:
        print("Time of day: PM")

date_time_input = input("Enter date and time in format MM/DD/YYYY HR:MIN:SEC: ")
validate_and_print_datetime(date_time_input)
