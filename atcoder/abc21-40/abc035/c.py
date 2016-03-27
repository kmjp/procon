import sys

N,Q=map(int,raw_input().strip().split(" "))
A=[0]*(N+1)

for i in range(Q):
	L,R=map(int,raw_input().strip().split(" "))
	A[L-1] += 1
	A[R] += 1

X = 0
for i in range(N):
	X += A[i]
	sys.stdout.write("%d" % (X&1))
print
