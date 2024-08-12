'''
Question 13.  Further, in the above question, find the income tax slab in which 
the employee lies. 
Gross Salary                             Income Tax 
< Rs. 3 LPA                          0% 
Rs. 3,00,000 - Rs. 10,00,000         10% of the gross salary 
Rs. 10,00,000 - Rs. 25,00,000        20% of the gross salary 
Above Rs. 25,00,000                  30% of the gross salary
'''
basic_salary = int(input("Enter Basic Salary : "))
HRA = basic_salary/5
TA = basic_salary/20
DA = basic_salary/10
gross_salary = basic_salary + HRA+TA+DA
print("You are under : ",end="")
if gross_salary<300000:
    print("0% tax slab")
elif gross_salary<1000000:
    print("10% tax slab")
elif gross_salary<2500000:
    print("20% tax slab")
else:
    print("30% tax slab")