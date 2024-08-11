'''
Question 6. Write a program that asks the user to enter a whole number of months 
as input and then converts that amount of time to years and months. 
The program should use both integer division and the modulus operator.
'''
value_in_months = int(input("Enter whole number of months : "))
print(f"It is {value_in_months//12} years and {value_in_months%12} months")