'''
Given a string Str which may contain lowercase and uppercase characters. 
The task is to remove all duplicate characters from the string and find 
the resultant string. The order of remaining characters in the output should 
be same as in the original string.

Input Format
• Each testcase contains a string.
Output Format
• Output the string with duplicates.

Testcases:

Sample Input O
youARegEnilJs
Sample Output O
youARegEniUs

Sample Input I
HaPpyNewYear
Sample Output 1
HaPpyNewYr

Sample Input 2
WeeKlyContesT
Sample Output 2
WeKlyContsT

'''
if __name__ == '__main__':
    with open("Coding Hour\\Week1\\05_testcases.txt",'r') as fptr:
        str = fptr.readline().strip()
        length = len(str)
        seen = set()
        new = ""
        for i in str:
            if i not in seen:
                seen.add(i)
                new+=i
        print(new) 