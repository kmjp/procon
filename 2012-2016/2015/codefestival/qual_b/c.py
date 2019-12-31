
N,M=map(int,raw_input().strip().split(" "))
A=map(int,raw_input().strip().split(" "))
B=map(int,raw_input().strip().split(" "))

A.sort()
B.sort()

ok = 0
if N>=M:
	ok = 1
	for i in range(M):
		if A[N-M+i] < B[i]:
			ok = 0

if ok > 0:
	print "YES"
else:
	print "NO"
