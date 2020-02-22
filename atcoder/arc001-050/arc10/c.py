import sys
import copy

N,M,Y,Z=map(int,raw_input().split(" "))
T={}
I={}
for i in range(M):
	c,v=raw_input().split(" ")
	T[c]=(i,int(v))

DP=[[[-99999999 for i in range(1<<M)] for j in range(M)] for k in range(2)]
DP[0][0][0]=0
B=list(raw_input())

for i in xrange(N):
	cur = i%2
	tar = cur^1
	for j in xrange(M<<M):
		DP[tar][j>>M][j%(1<<M)]=DP[cur][j>>M][j%(1<<M)]
	
	# continue
	ci=T[B[i]][0]
	for c in xrange(M):
		for mask in xrange(1<<M):
			if c==ci and (mask & (1<<ci)):
				DP[tar][ci][mask | (1<<ci)] = max(DP[tar][ci][mask | (1<<ci)], DP[cur][c][mask]+T[B[i]][1]+Y)
			else:
				DP[tar][ci][mask | (1<<ci)] = max(DP[tar][ci][mask | (1<<ci)], DP[cur][c][mask]+T[B[i]][1])

ma=0
for c in range(M):
	for mask in range((1<<M)-1):
		ma=max(ma,DP[N%2][c][mask])
	ma=max(ma,DP[N%2][c][(1<<M)-1]+Z)

print(ma)

