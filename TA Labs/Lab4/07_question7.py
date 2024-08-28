'''
Question 7. Most of the people start planning their vacations well in advance. 
A young programmer from Bulgaria has a certain budget (BGN is the currency of 
Bulgaria) and spare time in a particular season. 
Write  a  program  that  accepts  as  input  the  budget  and  season  and  as  
output  displays programmer's vacation place and the amount of money they will spend. 
The budget determines the destination, and the season determines what amount of the 
budget will be spent. If the season is summer, the programmer will go camping, 
if it is winter - he will stay in a hotel. If it is in Europe, regardless of the 
season, the programmer will stay in a hotel. Each camp or hotel, according to the 
destination, has its price, which corresponds to a particular percentage of the 
budget: 
    • If 100 BGN or less - somewhere in Bulgaria. 
    Summer - 30% of the budget 
    Winter - 70% of the budget. 
    • If 1000 BGN or less - somewhere in the Balkans. 
    Summer - 40% of the budget. 
    Winter - 80% of the budget. 
    • If more than 1000 BGN - somewhere in Europe. 
Upon traveling in Europe, regardless of the season, the programmer will 
spend 90% of the budget.
'''
# Read input values
budget = float(input("Enter your budget (BGN): "))
season = input("Enter the season (summer/winter): ").lower()

# Initialize variables
destination = ""
place = ""
amount_spent = 0.0

# Determine the destination and amount spent based on budget and season
if budget <= 100:
    destination = "Bulgaria"
    if season == "summer":
        place = "Camp"
        amount_spent = budget * 0.30
    else:  # winter
        place = "Hotel"
        amount_spent = budget * 0.70
elif budget <= 1000:
    destination = "Balkans"
    if season == "summer":
        place = "Camp"
        amount_spent = budget * 0.40
    else:  # winter
        place = "Hotel"
        amount_spent = budget * 0.80
else:
    destination = "Europe"
    place = "Hotel"
    amount_spent = budget * 0.90

# Print the result
print(f"Somewhere in {destination}")
print(f"{place} - {amount_spent:.2f} BGN")