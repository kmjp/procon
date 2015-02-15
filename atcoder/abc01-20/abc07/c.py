import sys
from collections import deque

H,W=map(int,raw_input().strip().split(" "))
sy,sx=map(int,raw_input().strip().split(" "))
gy,gx=map(int,raw_input().strip().split(" "))

M=[]
for y in range(0,H):
	M.append(raw_input().strip())

dist=[10000] * 10000
dist[sy*100+sx-101]=0

dx=[1,-1,0,0]
dy=[0,0,1,-1]

q=deque([sy*100+sx-101])

while len(q)>0:
	k=q.popleft()
	cy = k/100
	cx = k%100
	for i in range(0,4):
		ty=cy+dy[i]
		tx=cx+dx[i]
		if M[ty][tx]=="#":
			continue
		if dist[ty*100+tx]<=dist[cy*100+cx]+1:
			continue;
		dist[ty*100+tx]=dist[cy*100+cx]+1
		q.append(ty*100+tx)

print dist[gy*100+gx-101]

