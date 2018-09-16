N,M=map(int,raw_input().strip().split(" "))
mat=[0]*N
for i in range(M):
	a,b=map(int,raw_input().strip().split(" "))
	mat[a-1] |= 1<<(b-1)

dp=[0]*(1<<N)
dp[0]=1
for mask in range(1,1<<N):
	for i in range(N):
		if (mask & (1<<i)):
			if (mat[i] & mask)==0:
				dp[mask] += dp[mask ^ (1<<i)]

print dp[(1<<N)-1]
