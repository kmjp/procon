
import sys
import math

N=input()

ma=0
for i in range(N/2-10,N/2+10):
	if i>=1 and i<N:
		ma=max(ma,(N-i+1)*(i+1)-1)

print ma%1000007


