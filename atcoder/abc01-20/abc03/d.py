import sys

mo = 1000000007
R,C=map(int,raw_input().strip().split(" "))
X,Y=map(int,raw_input().strip().split(" "))
D,L=map(int,raw_input().strip().split(" "))

co=[[0 for i in range(1000)] for j in range(1000)]

for x in range(1000):
	co[x][x]=1

for x in range(1,1000):
	for y in range(0,x+1):
		co[x][y] = (co[x-1][y-1] + co[x-1][y]) % mo

ret = 0
for i in range(16):
	xx=X
	yy=Y
	pa=0
	if i & 1:
		xx-=1
		pa+=1
	if i & 2:
		xx-=1
		pa+=1
	if i & 4:
		yy-=1
		pa+=1
	if i & 8:
		yy-=1
		pa+=1
	if xx>=0 and yy>=0 and xx*yy>=D+L:
		if pa % 2 == 0:
			ret += co[xx*yy][D+L]
		else:
			ret -= co[xx*yy][D+L]

ret = ((ret%mo)+mo)%mo
ret = ret * (R-X+1) * (C-Y+1) * co[D+L][L] % mo
print ret



