'''
Question 9. A store sells widgets at 25 cents each for small orders or at 20 cents 
each for orders of 100 or more. Write a program that requests the number of 
widgets ordered and displays the total cost.
'''
widgets = int(input("Enter number of widgets you want to buy : "))
if widgets<100:
    print(f"Your Cost Would Be {(widgets*25)//100} dollars and {(widgets*25)%100} cents")
else:
    print(f"Your Cost Would Be {(widgets*20)//100} dollars and {(widgets*20)%100} cents")