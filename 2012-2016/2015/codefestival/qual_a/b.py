N=input()
A=map(int,raw_input().strip().split(" "))
C=0

for i in range(N):
	C = C*2 + A[i]
print C
