import sys

N=input()
S=[]
for i in range(0,N):
	S.append(raw_input()[::-1])

S.sort()
for i in range(0,N):
	print(S[i][::-1])



