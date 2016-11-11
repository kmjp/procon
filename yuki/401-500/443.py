import sys
import math

def gcd(a, b):
	return a if b == 0 else gcd(b, a%b)

N = raw_input()
S = set()

for c in N:
	S.add(int(c))

if len(S) == 1:
	print N
else:
	G = 0
	for y in S:
		for x in S:
			if y > x:
				G = gcd(G, 9*(y-x))
	print gcd(int(N),G)



