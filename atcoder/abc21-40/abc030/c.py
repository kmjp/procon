import bisect

N,M=map(int,raw_input().strip().split(" "))
X,Y=map(int,raw_input().strip().split(" "))
A=map(int,raw_input().strip().split(" "))
B=map(int,raw_input().strip().split(" "))

t = 0
lp = 0

while 1:
	
	id = bisect.bisect_left(A, t)
	if id>=N:
		break
	t = A[id]+X
	
	id = bisect.bisect_left(B, t)
	if id>=M:
		break
	t = B[id]+Y
	lp += 1

print lp
