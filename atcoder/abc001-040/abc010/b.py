import sys

ok=[0,0,1,0,1,2,3,0,1,0]

N=input()
K=map(int,raw_input().strip().split(" "))
R=0
for i in K:
	R += ok[i]

print R


