
N=input()
A=map(int,raw_input().strip().split(" "))
B = []
for i in range(N):
	B.append((A[i],i+1))

B.sort()
B.reverse()
for b in B:
	print b[1]
