'''
Question 1. A company decided to give bonus of 5% to employee if his/her year of 
service is more than 5 years. Ask user for their salary and years of service and 
print the net bonus amount.
'''
#Taking salary input
salary = int(input("Enter Salary : "))
#Taking years of service from the user
years_of_salary = float(input("Enter Years of Salary : "))
#Calculating net bonus
bonus = 0
if years_of_salary>=5:
    print(f"Your bonus amount is {salary/20:.2f}")
else:
    print(f"You are not eligible for bonus")