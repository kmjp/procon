import sys
import math

N,M=map(int,raw_input().strip().split(" "))
X0,A,P=map(int,raw_input().strip().split(" "))

if A == 0:
	if X0 >= P:
		print 2*(N-1)
	else:
		print 0
	sys.exit(0)

X=[]
for i in range(0,N*M):
	X.append((X0,i))
	X0 = (X0 + A) % P

X.sort()

ret = 0
for y in range(0,N):
	L=[]
	for x in range(0,M):
		ret += math.fabs(X[y*M+x][1]/M - y)
		L.append(X[y*M+x][1]%M)
	L.sort()
	for i in range(0,M):
		ret += math.fabs(L[i]-i)

print int(ret)


