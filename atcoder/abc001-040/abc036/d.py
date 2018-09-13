
N=input()
M=1000000007
W=[0]*N
B=[0]*N

E = []
for i in range(N):
	E.append([])

def dfs(cur,pre):
	W[cur] = B[cur] = 1
	for r in E[cur]:
		if r != pre:
			dfs(r,cur)
			W[cur] = W[cur] * (W[r]+B[r]) % M
			B[cur] = B[cur] * W[r] % M


for i in range(N-1):
	x,y=map(int,raw_input().strip().split(" "))
	E[x-1].append(y-1)
	E[y-1].append(x-1)

dfs(0,-1)
print (W[0]+B[0])%M

