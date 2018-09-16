W=input()
N,K=map(int,raw_input().strip().split(" "))

dp=[[12000000 for i in range(5001)] for j in range(51)]
dp[0][0] = 0

tot=0
for i in range(N):
	A,B=map(int,raw_input().strip().split(" "))
	
	for x in range(i,-1,-1):
		for y in range(tot,-1,-1):
			dp[x+1][y+B] = min(dp[x+1][y+B], dp[x][y]+A)
	tot += B

ma=0
for i in range(0,K+1):
	for j in range(0,5001):
		if dp[i][j]<=W:
			ma = max(ma,j)

print ma

