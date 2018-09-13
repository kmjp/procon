import sys
import math

N,K=map(int,raw_input().strip().split(" "))
val=[0]*101000
tot=0

for i in range(0,N):
	x,y,z=map(int,raw_input().strip().split(" "))
	tot += z
	val[x]+=z
	val[y+1]-=z

ret = 0
for i in range(1,K+1):
	val[i]+=val[i-1]
	ret = max(ret, tot-val[i])

print ret


