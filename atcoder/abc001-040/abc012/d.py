import sys

N,M=map(int,raw_input().strip().split())

D = [[1000000 for j in range(300)] for i in range(300)]
for i in range(0,N):
	D[i][i]=0

for i in range(0,M):
	a,b,t = map(int,raw_input().strip().split())
	D[a-1][b-1]=D[b-1][a-1]=t

A=range(0,N)
B=range(0,N)
C=range(0,N)

for i in A:
	for x in B:
		t = D[x][i]
		for y in C:
			if D[x][y] > t+D[i][y]:
				D[x][y] = t+D[i][y]

res=1000000
for i in range(0,N):
	ma = 0
	for j in range(0,N):
		if ma < D[i][j]:
			ma = D[i][j]
	if res > ma:
		res = ma

print res
