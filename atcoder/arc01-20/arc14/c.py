import sys

N=input()
W=raw_input().strip()
A={}

for i in range(N):
	A[W[i]]=A.get(W[i],0)+1

print(A.get('R',0)%2 + A.get('G',0)%2 + A.get('B',0)%2)

