import sys

def dfs(cur):
	global vis
	global EE
	vis[cur] = 1
	if cur==100:
		return 1
	for i in range(101):
		if vis[i]==0 and EE[cur][i]>0 and dfs(i) > 0:
			EE[cur][i] -= 1
			EE[i][cur] += 1
			return 1
	return 0

N,G,E=map(int,raw_input().strip().split(" "))
EE = [[0 for x in range(101)] for y in range(101)]
vis = [0] * 101

if G==0:
	print 0
	sys.exit(0)
	
for i in map(int,raw_input().strip().split(" ")):
	EE[i][100] = 1

for i in range(0,E):
	x,y=map(int,raw_input().strip().split(" "))
	EE[x][y] = EE[y][x] = 1

flow=0
while 1:
	for i in range(0,101):
		vis[i] = 0
	if dfs(0) == 0:
		break
	flow += 1

print flow


