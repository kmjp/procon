import sys

N,M=map(int,raw_input().strip().split(" "))

if N==M:
	print 0
	sys.exit()

X=[]
for i in range(M):
	X.append(input())

def dodo(v):
	right = 0
	for x in X:
		if right >= x-1:
			right = x+v
		else:
			if x-v > right+1:
				return False
			right = max(x+(v-(x-right-1))/2,x+(v-(x-right-1)*2))
	
	return right >= N


ret = 0
for i in range(30,-1,-1):
	if not dodo(ret + (1<<i)):
		ret += 1<<i

print ret+1

