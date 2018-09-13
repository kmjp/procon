import sys
import array

N = input()
P = []
D = [0]*1000005
E = []

def dfs(cur):
	for tar in E[cur]:
		if tar != P[0][cur]:
			D[tar] = D[cur]+1
			P[0][tar] = cur
			dfs(tar)

def par(cur,dep):
	for i in range(0,17):
		if dep & (1<<i):
			cur = P[i][cur]
	return cur

def dist(x,y):
	ret = 0
	if D[x] > D[y]:
		x,y=y,x
	
	for i in range(17)[::-1]:
		if D[y]-D[x] >= 1<<i:
			ret += 1<<i
			y = P[i][y]
	
	for i in range(17)[::-1]:
		if P[i][x] != P[i][y]:
			ret += 2<<i
			x = P[i][x]
			y = P[i][y]
	
	if x != y:
		ret += 2
	return ret

for i in range(0,17):
	P.append([0]*100005)
	
for i in range(0,N):
	E.append(array.array('l'))

for i in range(0,N-1):
	x,y=map(int,raw_input().strip().split())
	E[x-1].append(y-1)
	E[y-1].append(x-1)

dfs(0)

for i in range(0,16):
	for j in range(0,N):
		P[i+1][j] = P[i][P[i][j]]

Q = input()
while Q > 0:
	Q -= 1
	x,y=map(int,raw_input().strip().split())
	print dist(x-1,y-1)+1



