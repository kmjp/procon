import sys
import math
import Queue

N,M=map(int,raw_input().strip().split(" "))
mat=[[1<<60 for i in range(301)] for j in range(301)]
use=[[0 for i in range(301)] for j in range(301)]

for i in range(M):
	x,y,l=map(int,raw_input().strip().split(" "))
	mat[x-1][y-1]=mat[y-1][x-1]=l

for i in range(1,N):
	for x in range(1,N):
		for y in range(1,N):
			mat[x][y]=min(mat[x][y],mat[x][i]+mat[i][y])

mi=1<<60
for x in range(1,N):
	for y in range(x+1,N):
		mi = min(mi, mat[0][x] + mat[x][y] + mat[y][0])

if mi >= 1<<60:
	mi = -1
print mi

