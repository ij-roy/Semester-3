'''
Given two strings a and b consisting of lowercase characters. 
The task is to check whether two given strings are an anagram of each other or not.
An anagram of a string is another string that contains the same characters, 
only the order of characters can be different. 
For example, act and tac are an anagram of each other. 
Strings a and b can only contain lower case alphabets.

Input Format
• First line contains string a.
• Second line contains string b.
Output Format
• If the strings are anagrams, you must return YES or else return NO

Testcases:

Sample Input O
allergy
allergic
Sample Output O
NO

Sample Input 1
geeksforgeeks
forgeeksgeeks
Sample Output I
YES

Sample Input 2
leetcode
codelete
Sample Output 2
YES

'''

def anagram(str1,str2):
    if len(str1) != len(str2):
        return "NO"
    if sorted(str1) == sorted(str2):
            return "YES"
    else:
         return "NO"
    
if __name__ == '__main__':
    with open("Coding Hour\\Week1\\06_testcases.txt",'r') as fptr:
        str1 = fptr.readline().strip()
        str2 = fptr.readline().strip()

        result = anagram(str1,str2)
        print(result)

