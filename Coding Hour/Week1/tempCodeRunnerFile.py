'''
Rahul owns an ice cream shop in Jaipur named Jal Mahal Ice-Cream parlour. 
There are only three types of coins in Jaipur: Rs. 5, Rs. 10 and Rs. 15. 
An ice cream costs Rs. 5.

There are N people (numbered 1 through N) standing in a queue to buy ice cream 
from Jal Mahal Ice-Cream parlour. Each person wants to buy exactly one ice cream. 
For each valid i, the i-th person has one coin with value a i . 
It is only possible for someone to buy an ice cream when Rahul can give them back 
their change exactly

For example, if someone pays with a Rs. 10 coin, Rahul needs to have a Rs. 5 coin 
that he gives to this person as change. Initially, Rahul has no money. He wants to 
know if he can sell ice cream to everyone in the queue, in the given order. 
Tell him if he can serve all these people

Input Format

The first line of the input contains a single integer T denoting the number of test cases.
The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers a1,a2,…,aN .
Constraints

1 ≤ T ≤ 100
1 ≤ N ≤ 1000
Output Format

For each test case, print a single line containing the string "YES" if all people can be served or "NO" otherwise (without quotes).
Sample Input 0

3
2
10
5
2
5
15
6
5
5
10
5
5
20

Sample Output 0

NO
NO
YES