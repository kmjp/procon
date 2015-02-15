import sys

N,M,D=map(int,raw_input().strip().split())
R=map(int,raw_input().strip().split())

A = [[0 for i in range(N)] for j in range(2)]
B = [[0 for i in range(N)] for j in range(2)]
Rev = [0 for i in range(N)]

for i in range(0,N):
	A[0][i]=B[0][i]=i

for i in R:
	A[0][i-1],A[0][i]=A[0][i],A[0][i-1]

for i in range(0,30):
	cur=i%2
	tar=cur^1
	for x in range(0,N):
		A[tar][x]=A[cur][A[cur][x]]
		if (D & (1<<i))>0:
			B[tar][x]=A[cur][B[cur][x]]
		else:
			B[tar][x]=B[cur][x]

for x in range(0,N):
	Rev[B[0][x]]=x
	
for x in range(0,N):
	print Rev[x]+1
