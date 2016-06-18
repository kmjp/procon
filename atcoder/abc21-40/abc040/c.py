N=input()
A=map(int,raw_input().strip().split(" "))
C=[0]*N
for i in range(1,N):
	C[i] = C[i-1] + abs(A[i]-A[i-1])
	if i>1:
		C[i] = min(C[i], C[i-2] + abs(A[i]-A[i-2]))

print C[N-1]
