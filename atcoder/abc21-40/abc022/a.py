import sys
import math

N,S,T=map(int,raw_input().strip().split(" "))
ret=0
W=0
for i in range(N):
	W+=input()
	if S<= W <=T:
		ret += 1

print ret
