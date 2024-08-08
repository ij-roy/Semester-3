'''
You would like to withdraw X $US from an ATM.
The cash machine will only accept the transaction if X is a multiple of 5, 
and your account balance has enough cash to perform the withdrawal transaction 
(including bank charges).
For each successful withdrawal the bank charges 0.50 $US.
Calculate your account balance after an attempted transaction.
Input Format

Each input contains 2 integers X and Y.
X is the amount of cash which Pooja wishes to withdraw.
Y is your initial account balance
Constraints

0 < X ≤ 2000
0 < Y ≤ 2000
Output Format

Output the account balance after the attempted transaction, given as a number 
with two digits of precision. If there is not enough money in the account to 
complete the transaction, output the current bank balance.

Sample Input :
42
120.00

Sample Output :
120

Difficulty: Easy

'''

def calculate_balance(x,y):
    if x%5 != 0:
        return y
    elif y> (x+0.5):
        return y-x-0.5
    else:
        return y

if __name__ == '__main__':
    fptr = open('Coding Hour\\Week1\\03_testcases.txt','r')

    x = int(fptr.readline().strip())
    y = float(fptr.readline().strip())

    balance = calculate_balance(x,y)
    
    print(f"{balance:.2f}")

    fptr.close()
    