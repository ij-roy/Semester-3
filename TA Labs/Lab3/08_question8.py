'''
Question 8. Suppose you save $100 each month into a savings account with an annual 
interest rate of 5%. Therefore, the monthly interest rate is 0.05/12 = 0.00417. 
After the first month, the value in the account becomes
        100 * (1 + 0.00417) = 100.417
        After the second month, the value in the account becomes
        (100 + 100.417) * (1 + 0.00417) = 201.252
        After the third month, the value in the account becomes
        (100 + 201.252) * (1 + 0.00417) = 302.507
        and so on.
Write a program that prompts the user to enter a monthly saving amount, number 
of months (N) and displays the account value after the Nth  month. 
Check for valid and invalid cases. Do not use loops.
'''
monthly_saving = float(input("Enter the monthly saving amount: "))
months = int(input("Enter the number of months: "))
while monthly_saving < 0 or months < 0:
    print("Monthly saving amount and number of months must be non-negative.")
    monthly_saving = float(input("Enter the monthly saving amount: "))
    months = int(input("Enter the number of months: "))
monthly_interest_rate = 0.05 / 12
final_value = (monthly_saving * (1 + monthly_interest_rate)**months - monthly_saving) / monthly_interest_rate
print(f"The account value after {months} months is: {final_value:.2f}")