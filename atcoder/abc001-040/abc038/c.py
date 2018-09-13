N=input()
A=map(int,raw_input().strip().split(" "))
ret = L = 0

for i in range(N):
	if i>0 and A[i]<=A[i-1]:
		L = i
	ret += i-L+1

print ret

