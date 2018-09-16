import sys

N=input()
S=set()
for i in range(0,N):
	S.add(input())

L=list(S)
L.sort()

print L[-2]


