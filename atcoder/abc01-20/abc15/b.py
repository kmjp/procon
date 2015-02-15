
import sys
N=input()
A=map(int,raw_input().strip().split(" "))

x=0
b=0
for i in A:
	x += i
	if i > 0:
		b += 1

print (x+b-1)/b
