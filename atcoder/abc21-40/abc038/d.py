N=input()
A = []

for i in range(N):
	A.append(map(int,raw_input().strip().split(" ")))
	A[-1][1] *= -1

A.sort()
P = [-x[1] for x in A]
LIS = [101010]*(N+1)
for i in P:
	L=0
	R=len(LIS)
	while L+1<R:
		t = (L+R)/2
		if LIS[t-1]<i:
			L=t
		else:
			R=t
	LIS[L]=i

for i in range(len(LIS)):
	if LIS[i]==101010:
		print i
		break

