import sys
import math

N=input()
ret=0
hist=[0]*101000

for i in range(N):
	x=input()
	if hist[x] > 0:
		ret += 1
	hist[x] = 1

print ret
