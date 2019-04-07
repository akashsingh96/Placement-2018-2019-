*
Given 2 numbers a and b, you have to return 2*x+3*y if solution exists for following equations:
x + y = a
x xor y = b
x >= 0 (https://www.geeksforgeeks.org/find-two-numbers-sum-xor/)
*/

Logic:
x+y=s;
x^y=xor;

y=x(min)+xor
x(min)=(s-xor)/2;
y=(s-xor)/2+xor;

Solution will always exit if s-xor>0 and (s-xor)%2==0

