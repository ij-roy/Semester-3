'''
Question 10. The a value of year as input and find whether it is a leap year or not. 
Consider all the cases of valid and invalid inputs. Write down the test cases for 
the same.
'''

year = int(input("Enter the Year : "))
while year<=0:
    print("Year is not valid")
    year = int(input("Enter the Year : "))

if year%4==0:
    if year%100 == 0:
        if year%400 == 0:
            print(f"{year} is a leap year")
        else:
            print(f"{year} is not a leap year")
    else:
        print(f"{year} is a leap year")
else:
    print(f"{year} is not a leap year")

'''
Test Cases:
    Enter the Year : 2000
    2000 is a leap year

    Enter the Year : 2100
    2100 is not a leap year

    Enter the Year : 2024
    2024 is a leap year

    Enter the Year : 2015
    2015 is not a leap year
'''