
import sys
N,K=map(int,raw_input().strip().split(" "))
A=[]

for i in range(0,N):
	A.append(map(int,raw_input().strip().split(" ")))

for i in range(0,K**N):
	v = 0
	for j in range(0,N):
		v ^= A[j][i // int(K**j) % K ]
	
	if v == 0:
		print "Found"
		sys.exit(0)

print "Nothing"
