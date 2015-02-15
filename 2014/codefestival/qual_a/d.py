import sys

A,K=map(int,raw_input().strip().split())

def dfs(cur,mask):
	if cur<0:
		return 0
	
	mi = 1<<60
	cd = A/(10**cur)%10
	left = A%(10**(cur+1))
	
	for d in range(0,10):
		mask2 = mask | (1<<d)
		if d==0 and mask==0:
			mask2 = 0
		
		bc = bin(mask2).count("1")
		if bc>K:
			continue
		
		val = d * (10**cur)
		if d == cd:
			val += dfs(cur-1, mask2)
		else:
			ds = 0
			if d < cd:
				for ds in range(9,-1,-1):
					if mask2 & (1<<ds):
						break
				if bc < K:
					ds = 9
			else:
				for ds in range(0,10):
					if mask2 & (1<<ds):
						break
				if bc < K:
					ds = 0
			val += ((10**cur)-1)/9*ds
		
		if abs(val - left) < abs(mi - left):
			mi = val
	return mi

print abs(A - dfs(19,0))

