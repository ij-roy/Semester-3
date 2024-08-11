'''
Question 7. The  color  of  the  beacon  light  atop  Boston’s  old  John  Hancock  
building  forecasts  the weather according to the following rhyme:  
Steady blue, clear view.  
Flashing blue, clouds due.  
Steady red, rain ahead.  
Flashing red, snow instead.  
Write a program  that requests a color (Blue or Red) and a mode (Steady or Flashing) as 
input and then displays the weather forecast.
'''
def weather_forecast(colour , mode):
    if colour == 'Blue'and mode == 'Steady' :
        print("Clear Blue") 
    elif colour == 'Red' and mode == 'Flashing':
        print("Clouds Due")
    elif colour == 'Red' and mode == 'Steady' :
        print("Rain Ahead")
    elif colour == 'Red' and mode == 'Flashing' :
        print("Snow Instead")
    else:
        print("Invalid Input")
        weather_forecast(colour,mode)
    

colour = input("Enter Color Blue or Red : ")
mode = input("Enter mode Steady or Flashing : ")
print("Weather Is : ",end="")
weather_forecast(colour,mode)