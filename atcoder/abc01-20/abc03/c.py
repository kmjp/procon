import sys

N,K=map(int,raw_input().strip().split(" "))
R=map(int,raw_input().strip().split(" "))

R.sort()
r=0.0

for i in range(0,K):
	r = (r+R[N-K+i])/2.0
print r
