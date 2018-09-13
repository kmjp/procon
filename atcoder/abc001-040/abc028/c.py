
import sets

A=map(int,raw_input().strip().split(" "))

S = set()
for x in range(5):
	for y in range(x):
		for z in range(y):
			S.add(A[x]+A[y]+A[z])

T=list(S)
T.sort()
print T[-3]
