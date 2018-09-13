import sys

N=input()
D=[]
for y in range(0,N):
	D.append(map(int,raw_input().strip().split(" ")))

S=[[0 for j in range(N+1)] for i in range(N+1)]

for y in range(0,N):
	for x in range(0,N):
		S[y+1][x+1]=S[y+1][x]+D[y][x]

for y in range(0,N):
	for x in range(0,N):
		S[y+1][x+1]+=S[y][x+1]

M=[0] * 2501
for y in range(0,N):
	for x in range(0,N):
		for h in range(0,N-y):
			for w in range(0,N-x):
				v = S[y+h+1][x+w+1]+S[y][x]-S[y+h+1][x]-S[y][x+w+1]
				M[(h+1)*(w+1)]=max(M[(h+1)*(w+1)],v)

for i in range(1,2500):
	M[i]=max(M[i],M[i-1])

Q=input()
for i in range(0,Q):
	x=input()
	print M[x]

