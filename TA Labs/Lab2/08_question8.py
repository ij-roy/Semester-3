'''
Question 8. Write a program that requests the costs and revenue for a company and 
displays the message “Break even” if the costs and revenue are equal; 
otherwise, it displays the profit or loss
'''
profit = int(input("Enter Profit : "))
loss = int(input("Enter Loss : "))
if profit==loss:
    print("Break even")
elif profit>loss:
    print(f"Profit is {profit-loss} rupees")
else:
    print(f"Loss is {loss-profit} rupees")