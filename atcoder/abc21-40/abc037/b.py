N,Q=map(int,raw_input().strip().split(" "))

A=[0]*N

for i in range(Q):
	L,R,T=map(int,raw_input().strip().split(" "))
	for x in range(L-1,R):
		A[x] = T

for a in A:
	print a
