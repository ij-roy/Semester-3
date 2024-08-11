'''
Question 2. If  the  lengths  of  the  two  parallel  sides  of  a  trapezoid  
are  X  meters  and  Y  meters, respectively, and the height is H meters, 
what is the area of the trapezoid? Write Python code to output the area by taking X, 
Y and H as input from the user
'''
#Area of trapezoid : ((X+Y)*h)/2
x = int(input("Enter Length of 1st parallel side : "))
y = int(input("Enter Length of 2nd parallel side : "))
h = int(input("Enter Height : "))
area = ((x+y)*h)/2
print(f"Area is : {area}")