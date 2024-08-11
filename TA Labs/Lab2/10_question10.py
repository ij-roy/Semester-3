'''
Question 10.  A supermarket sells apples for $2.50 per pound. 
Write a cashier’s program that requests the number of pounds and the amount of cash 
tendered as input and displays the change from the transaction. 
If the cash is not enough, the message “You owe $x.xx more.” should be 
displayed, where $x.xx is the difference between the total cost and the cash.
'''
pound = float(input("Enter number of pounds : "))
cash = float(input("Enter the tendered amount : "))
price = pound*2.50
if(cash<price):
    print(f"You owe ${price-cash:.2f}")
else:
    print(f"Here is the change of ${cash-price:.2f}")