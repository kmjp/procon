import sys
import math

N,M=map(int,raw_input().strip().split(" "))
dp=[0]*(N+2)
S=[0]*(N+2)

dp[1]=S[1]=1
mo=1000000007
prev=[1]*100003

le=1
for i in range(0,N):
	f=input()
	le = max(le, prev[f])
	
	dp[i+2]=(S[i+1]-S[le-1]+mo)%mo
	S[i+2]=(S[i+1]+dp[i+2])%mo
	prev[f]=i+2

print ((dp[N+1]%mo)+mo)%mo
