import sys

W,H=map(int,raw_input().strip().split(" "))
N=input()
X=[]
Y=[]
for i in range(0,N):
	x,y=map(int,raw_input().strip().split(" "))
	X.append(x)
	Y.append(y)

memo = {}

def dfs(l,r,t,b):
	if l > r or t > b :
		return 0
	key = (l,r,t,b)
	if key in memo:
		return memo[key]
	
	memo[key] = 0
	for i in range(0,N):
		if X[i]>=l and X[i]<=r and Y[i]>=t and Y[i]<=b:
			memo[key] = max(memo[key], r-l+b-t+1 + 
				dfs(l,X[i]-1,t,Y[i]-1)+dfs(X[i]+1,r,t,Y[i]-1)+
				dfs(l,X[i]-1,Y[i]+1,b)+dfs(X[i]+1,r,Y[i]+1,b))
	
	return memo[key]

print dfs(1,W,1,H)

