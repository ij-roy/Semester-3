'''
Question 5. A student has to travel n kilometers. He can choose between 
three types of transportation: 
    Taxi. Starting fee: 33.58 INR. Day rate: 37.89 INR/km. Night rate: 43.17 INR/km. 
    Bus. Day / Night rate: 4.32 INR/km. Can be used for distances of a minimum of 
    20 km. 
    Train. Day / Night rate: 2.88 INR/km. Can be used for distances of a minimum of 
    100 km. 
Write a program that reads the number of kilometers n and period of the day 
(day or night) and calculates the price for the cheapest transport.
'''
# Read input values
n = float(input("Enter the number of kilometers: "))
time_of_day = input("Enter the period of the day (day/night): ").lower()

# Initialize the cost to a large number
cheapest_cost = float('inf')

# Calculate the cost for each transportation option

# Taxi
if time_of_day == "day":
    taxi_cost = 33.58 + (37.89 * n)
else:
    taxi_cost = 33.58 + (43.17 * n)
if taxi_cost < cheapest_cost:
    cheapest_cost = taxi_cost

# Bus (only if the distance is at least 20 km)
if n >= 20:
    bus_cost = 4.32 * n
    if bus_cost < cheapest_cost:
        cheapest_cost = bus_cost

# Train (only if the distance is at least 100 km)
if n >= 100:
    train_cost = 2.88 * n
    if train_cost < cheapest_cost:
        cheapest_cost = train_cost

# Output the cheapest cost
print(f"The cheapest cost for traveling {n} kilometers is: {cheapest_cost:.2f} INR")