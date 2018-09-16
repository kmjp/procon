import sys

N,X=map(int,raw_input().strip().split())
A=map(int,raw_input().strip().split())
ret=0

for i in range(0,N):
	if (X & (1<<i)) > 0:
		ret+=A[i]

print ret

