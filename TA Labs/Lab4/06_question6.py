'''
Question 6. Tom Cat likes to sleep all day but, unfortunately, his owner is always 
playing with him whenever he has free time. To sleep well, the norm of games that 
Tom has is 30,000 minutes per year. The time for games he has depends on the 
holidays that his owner has: 
    • During workdays, his owner plays with him 63 minutes per day. 
    • During holidays, his owner plays with him 127 minutes per day. 
Write a program that reads the number of holidays and prints whether Tom can sleep 
well and how much the difference from the norm for the current year is. 
It is assumed that there are 365 days in one year
'''
# Constants
norm_minutes_per_year = 30000
minutes_played_workday = 63
minutes_played_holiday = 127
total_days_in_year = 365

# Read the number of holidays
holidays = int(input("Enter the number of holidays: "))

# Calculate the number of workdays
workdays = total_days_in_year - holidays

# Calculate the total playtime
total_playtime = (workdays * minutes_played_workday) + (holidays * minutes_played_holiday)

if total_playtime > norm_minutes_per_year:
    excess_minutes = total_playtime - norm_minutes_per_year
    print("Tom will run away")
    print(f"{excess_minutes} minutes more than the norm")
else:
    remaining_minutes = norm_minutes_per_year - total_playtime
    print("Tom sleeps well")
    print(f"{remaining_minutes} minutes less than the norm")