import sys
import math

N,D,K=map(int,raw_input().strip().split(" "))
L=[]
R=[]

for i in range(D):
	l,r=map(int,raw_input().strip().split(" "))
	L.append(l)
	R.append(r)

for x in range(K):
	S,T=map(int,raw_input().strip().split(" "))
	
	for i in range(D):
		if L[i] <= S <= R[i]:
			if S > T:
				S = max(L[i],T)
			elif S < T:
				S = min(R[i],T)
			
			if S==T:
				print i+1
				break


