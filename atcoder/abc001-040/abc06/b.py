import sys

N=input()
A=[0,0,1]

if N<=3:
	print A[N-1]
else:
	N -= 3
	while N > 0:
		N-=1
		A=[A[1],A[2],(A[0]+A[1]+A[2])%10007]
	
	print A[2]
