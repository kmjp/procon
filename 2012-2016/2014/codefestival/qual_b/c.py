import sys

def dfs(cur, mv):
	global vis
	global EE
	vis[cur] = 1
	if cur==30:
		return mv
	for i in range(0,31):
		if vis[i]==0 and EE[cur][i]>0:
			r = dfs(i, min(EE[cur][i], mv))
			if r > 0:
				EE[cur][i] -= r
				EE[i][cur] += r
				return r
	return 0

S = []
S.append(raw_input().strip())
S.append(raw_input().strip())
S.append(raw_input().strip())

C = [[0 for j in range(26)] for i in range(3)]
L = len(S[0])

for i in range(0,3):
	for j in range(0,L):
		C[i][ord(S[i][j])-ord("A")] += 1

EE = [[0 for x in range(31)] for y in range(31)]
vis = [0] * 31

EE[0][1] = EE[0][2] = L/2
for i in range(0,26):
	EE[1][3+i] = C[0][i]
	EE[2][3+i] = C[1][i]
	EE[3+i][30] = C[2][i]

flow=0
while 1:
	for i in range(0,31):
		vis[i] = 0
	f = dfs(0,100000)
	if f == 0:
		break
	flow += f

if flow==L:
	print "YES"
else:
	print "NO"
