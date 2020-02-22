import sys
import re

N,L=map(int,raw_input().split(" "))
T=range(0,N)

for a in range(0,L):
	S=raw_input()
	for i in range(0,N-1):
		if S[i*2+1]=='-':
			T[i],T[i+1]=T[i+1],T[i]

S=raw_input()
for i in range(0,N):
	if i*2 < len(S) and S[i*2]=='o':
		print(T[i]+1)


