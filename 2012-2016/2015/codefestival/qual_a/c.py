
N,T=map(int,raw_input().strip().split(" "))
L=[]
sum = -T
for i in range(N):
	A,B=map(int,raw_input().strip().split(" "))
	sum += A
	L.append(B-A)

ret = 0
L.sort()
for d in L:
	if sum > 0:
		ret += 1
		sum += d

if sum > 0:
	print -1
else:
	print ret
