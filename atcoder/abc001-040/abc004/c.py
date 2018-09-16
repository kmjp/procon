import sys

N=input()
N%=30
V=[1,2,3,4,5,6]

for i in range(0,N):
	j = i%5
	V[j],V[j+1] = V[j+1],V[j]

print "%d%d%d%d%d%d" % (V[0],V[1],V[2],V[3],V[4],V[5])



