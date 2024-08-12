'''
Question 12.  Calculate the gross salary of an employee by taking as input the 
basic Salary. HRA = 20% of basic salary, TA is 5% of basic salary, and DA is 10% 
of basic salary. Gross Salary = Basic Salary + HRA + TA + DA. 
'''
basic_salary = int(input("Enter Basic Salary : "))
HRA = basic_salary/5
TA = basic_salary/20
DA = basic_salary/10
gross_salary = basic_salary + HRA+TA+DA
print(f"Gross Salary is : ${gross_salary}")