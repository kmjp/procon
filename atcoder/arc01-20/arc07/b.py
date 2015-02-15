import sys

N,M=map(int,raw_input().split(" "))
C=range(0,N+1)

for i in range(0,M):
	d=input()
	for j in range(0,N+1):
		if C[j]==d:
			C[0],C[j]=C[j],C[0]
			break

for i in range(1,N+1):
	print(C[i])
