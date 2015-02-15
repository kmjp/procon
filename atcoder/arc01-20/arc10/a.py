import sys
 
N,M,A,B=map(int,raw_input().split(" "))
for i in range(M):
	if N <= A:
		N += B
	N -= input()
	if N < 0:
		print(i+1)
		exit()

print("complete")


