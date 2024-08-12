'''
Question 14.  The  flowchart  given  below  calculates  a  person’s  state  
income  tax.  Write  a  program corresponding to the flowchart.

Flowchart in pdf

'''

taxable_income = int(input("Enter Taxable Income : "))
if taxable_income <= 20000:
    tax = 0.02 * taxable_income
else:
    if taxable_income<=50000:
        tax = 400+(.025*(taxable_income-20000))
    else:
        tax = 1150 + (.035*(taxable_income-50000))
print(f"Your Tax is {tax:.2f} rupees")