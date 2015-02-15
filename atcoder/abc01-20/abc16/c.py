import sys
import math

N,M=map(int,raw_input().strip().split(" "))

mat = [[10000 for i in range(N)] for j in range(N)]

for i in range(N):
	mat[i][i] = 0

for i in range(M):
	A,B=map(int,raw_input().strip().split(" "))
	mat[A-1][B-1] = mat[B-1][A-1] = 1

for i in range(N):
	for x in range(N):
		for y in range(N):
			mat[x][y] = min(mat[x][y], mat[x][i]+mat[i][y]);

for i in range(N):
	cnt = 0
	for x in range(N):
		if mat[i][x] == 2:
			cnt += 1
	print cnt

