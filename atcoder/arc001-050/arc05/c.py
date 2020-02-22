import sys

H,W=map(int,raw_input().split(" "))
S=[]
sx=sy=gx=gy=0
for y in range(H):
	S.append(list(raw_input()))
	for x in range(W):
		if S[y][x]=="s":
			sx=x
			sy=y
			S[y][x]='.'
		if S[y][x]=="g":
			gx=x
			gy=y
			S[y][x]='.'

D=[[999999 for i in range(501)] for j in range(501)]
D[sy][sx]=0

Q=[[(sy,sx)],[],[],[]]
i=0
j=0
while 1:
	while j<3 and i>=len(Q[j]):
		i=0
		j+=1
	if j>=3:
		break
	cy,cx=Q[j][i]
	for dx in [(1,0),(-1,0),(0,1),(0,-1)]:
		tx = cx+dx[0]
		ty = cy+dx[1]
		if tx < 0 or tx >= W or ty < 0 or ty >= H:
			continue
		cc = D[cy][cx]
		if S[ty][tx]=="#":
			cc += 1
		if cc < D[ty][tx] and cc < 3:
			D[ty][tx]=cc
			Q[cc].append((ty,tx))
	i += 1

if D[gy][gx] <= 2:
	print("YES")
else:
	print("NO")




