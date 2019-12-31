import sys

N,M=map(int,raw_input().strip().split(" "))
A=map(int,raw_input().strip().split(" "))
C=[0]*101010

for x in A:
	C[x]+=1
for i in range(M+1):
	if C[i]*2 > N:
		print i
		sys.exit(0)

print '?'
