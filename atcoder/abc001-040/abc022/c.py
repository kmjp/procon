import sys
import math
import Queue

N,M=map(int,raw_input().strip().split(" "))
mat=[[1<<60 for i in range(301)] for j in range(301)]
group=[0]*301

for i in range(M):
	x,y,l=map(int,raw_input().strip().split(" "))
	mat[x-1][y-1]=mat[y-1][x-1]=l

dist = [1<<60] * N
dist[0]=0

Q = Queue.PriorityQueue()
Q.put((0,0))
while Q.qsize() > 0:
	ent = Q.get()
	co  = ent[0]
	cur = ent[1]
	if dist[cur] != co:
		continue
	
	for i in range(N):
		if mat[cur][i]>=0 and co + mat[cur][i] < dist[i]:
			if cur==0:
				group[i]=i
			else:
				group[i]=group[cur]
			dist[i] = co + mat[cur][i]
			Q.put((dist[i],i))

mi=1<<60
for x in range(1,N):
	if group[x] != x:
		mi = min(mi, dist[x]+mat[0][x])
	for y in range(x+1,N):
		if group[x] != group[y]:
			mi = min(mi, dist[x] + mat[x][y] + dist[y])

if mi >= 1<<60:
	mi = -1
print mi

