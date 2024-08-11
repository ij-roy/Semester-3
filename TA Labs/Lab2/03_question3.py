'''
Question 3. Write a program that interprets the Body Mass Index (BMI) based on a 
user's weight and height. 
It should tell them the interpretation of their BMI based on the BMI value. 
• Under 18.5 they are underweight 
• Over 18.5 but below 25 they have a normal weight 
• Over 25 but below 30 they are slightly overweight 
• Over 30 but below 35 they are obese 
• Above 35 they are clinically obese.

The BMI is calculated by dividing a person’s weight (in kg) by the square of their
height (in m). Take height and weight from the user.
'''
weight = float(input("Enter Weight in Kilogram : "))
height = float(input("Enter Weight in Metres : "))
BMI = weight/(height**2)
print("You Are : ",end="")
if BMI<18.5:
    print("UnderWeight")
elif BMI<25:
    print("Normal")
elif BMI <30:
    print("Slightly Overweight")
elif BMI<35:
    print("Obese")
else:
    print("Clinically Obese")