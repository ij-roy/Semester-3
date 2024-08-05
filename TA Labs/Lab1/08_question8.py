'''
Question 8. Take a value of temperature as input (in Celsius) and convert into 
degree Fahrenheit. Also, display the equivalent temperature in Kelvin.
'''

Celsius = float(input("Enter temperature in celsius : "))

# Fahrenheit = (9 / 5) * Celsius + 32
# Kelvin = Celsius + 273.15

print(f"{Celsius}°C in Fahrenheit is {(9 / 5) * Celsius + 32:.2f}°F and in Kelvin is {Celsius + 273.15:.2f}°K")