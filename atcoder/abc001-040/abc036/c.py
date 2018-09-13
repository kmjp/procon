
import bisect

N=input()
A=[0] * N
for i in range(N):
	A[i] = input()

V = []
for x in sorted(A):
	if len(V)==0 or x > V[-1]:
		V.append(x)

for r in A:
	print bisect.bisect_left(V,r)


