'''
Repeatedly take input from the user in the range of 1 – 10 till the time they enter -1. 
It then displays the histogram shown as follows. Note that the percentage values are 
displayed till 2 decimal places: 
       1 - 2: # # # # # # # # # # 52.00 % 
       3 - 4: # # # # # # 28.00 % 
       5 - 6: # 4.00 % 
       7 - 8: 0.00 % 
       9 - 10: # # # 16 %
'''

count_1_2 = 0
count_3_4 = 0
count_5_6 = 0
count_7_8 = 0
count_9_10 = 0
total_count = 0

n = int(input("Enter any integer between 1 to 10 \n(-1 to stop): "))
while(n!= -1):
    if 1 <= n <= 10:
       total_count += 1  # Increment total count
       
       # Increment the corresponding range counter
       if n in [1, 2]:
              count_1_2 += 1
       elif n in [3, 4]:
              count_3_4 += 1
       elif n in [5, 6]:
              count_5_6 += 1
       elif n in [7, 8]:
              count_7_8 += 1
       elif n in [9, 10]:
              count_9_10 += 1
       else:  
              print("Please enter a number between 1 and 10.")
    n = int(input("Enter any integer between 1 to 10 \n(-1 to stop): "))

print("\nHistogram:")
percentage_1_2 = (count_1_2 / total_count * 100) if total_count > 0 else 0
print(f"1 -  2: {'#' * count_1_2} {count_1_2} {percentage_1_2:.2f} %")

percentage_3_4 = (count_3_4 / total_count * 100) if total_count > 0 else 0
print(f"3 -  4: {'#' * count_3_4} {count_3_4} {percentage_3_4:.2f} %")

percentage_5_6 = (count_5_6 / total_count * 100) if total_count > 0 else 0
print(f"5 -  6: {'#' * count_5_6} {count_5_6} {percentage_5_6:.2f} %")

percentage_7_8 = (count_7_8 / total_count * 100) if total_count > 0 else 0
print(f"7 -  8: {'#' * count_7_8} {count_7_8} {percentage_7_8:.2f} %")

percentage_9_10 = (count_9_10 / total_count * 100) if total_count > 0 else 0
print(f"9 - 10: {'#' * count_9_10} {count_9_10} {percentage_9_10:.2f} %")