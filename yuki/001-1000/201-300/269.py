# -*- coding: utf-8 -*-
import sys
import math

N,S,K=map(int,raw_input().strip().split())
DP=[[0 for i in range(20005)] for j in range(105)]

mo = 1000000007

# 1人目だけは任意の(Nの倍数)円を寄付できる
for k in range(0,S+N,N):
	DP[1][k] = 1

# i番目の人
for i in range(2,N+1):
	# i番目の人が、(i-1)番の人より1円余分に払うと
	# 以降の人全体で(N+1-i)円払うことになる
	mult = N+1-i
	
	# t円にできるか？
	for t in range(0,S+1):
		# (i-1)番の人よりも最低K円余分に払う
		if t >= K*mult:
			DP[i][t] += DP[i-1][t - K*mult]
		
		# 既に全体(t-mult)円払っているが
		# もう1円(全体でmult円)余分に払うケース
		if t - mult >= 0:
			DP[i][t] += DP[i][t-mult]
		
		DP[i][t] %= mo

print DP[N][S]


