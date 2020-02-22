import sys

v99 = [0.99**i for i in range(500*501)]
Q=range(500*501)

def ok(P):
	Q[0]=sx*1000+sy
	vis=[[0 for a in range(W)] for b in range(H)]
	vis[sy][sx]=1
	dx=[(-1,0),(1,0),(0,1),(0,-1)]
	
	ql=1
	i=0
	while i<ql:
		pos=Q[i]
		x=pos/1000
		y=pos%1000
		for j in range(4):
			tx = x+dx[j][0]
			ty = y+dx[j][1]
			if tx < 0 or tx >= W or ty < 0 or ty >= H:
				continue
			
			if tx==gx and ty==gy:
				return 1
			if vis[ty][tx]>0:
				continue
			if M[ty][tx]*v99[vis[y][x]] >= P:
				vis[ty][tx]=vis[y][x]+1
				Q[ql]=tx*1000+ty
				ql += 1
		i+=1
	return 0

H,W=map(int,raw_input().split(" "))
M=[]
for i in range(H):
	M.append(list(raw_input()))

for y in range(H):
	for x in range(W):
		if M[y][x]=='s':
			sx=x
			sy=y
			M[y][x]=0.0
		elif M[y][x]=='g':
			gx=x
			gy=y
			M[y][x]=0.0
		elif M[y][x]=='#':
			M[y][x]=-1
		else:
			M[y][x]=float(M[y][x])

if ok(0)==0:
	print(-1)
	exit()

L=0.0
R=10.0
while R-L>0.0000000005:
	P = (L+R)/2.0
	#print(P)
	if ok(P):
		L=P
	else:
		R=P

print(L)
