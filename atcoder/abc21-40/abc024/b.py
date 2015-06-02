N,T=map(int,raw_input().strip().split(" "))

cur = -1
tot = 0
for i in range(N):
	A = input()
	if cur < A:
		tot += T
	else:
		tot += A + T - cur
	
	cur = A + T

print tot
