import sys
import math

N,M,P,Q,R = map(int,raw_input().strip().split(" "))
mat=[[0 for i in range(25)] for j in range(25)]

for i in range(R):
	x,y,z = map(int,raw_input().strip().split(" "))
	mat[x-1][y-1]=z

bits=[0]*512
low=[[0 for i in range(512)] for j in range(18)]
hi=[[0 for i in range(512)] for j in range(18)]

for mask in range(1<<min(N,9)):
	for i in range(min(N,9)):
		if mask & (1<<i):
			bits[mask]+=1
			for j in range(M):
				low[j][mask] += mat[i][j]

if N>9:
	for mask in range(1<<(N-9)):
		for i in range(N-9):
			if mask & (1<<i):
				for j in range(M):
					hi[j][mask] += mat[i+9][j]

ma = 0

for mask in range(1<<N):
	if bits[mask&511] + bits[mask>>9] != P:
		continue
	
	V=[]
	for i in range(M):
		V.append(low[i][mask&511] + hi[i][mask>>9])
	
	V.sort()
	ma=max(ma,sum(V[M-Q:]))

print ma

