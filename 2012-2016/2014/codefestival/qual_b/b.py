import sys
 
N,K=map(int,raw_input().strip().split())
for i in range(0,N):
	K -= input()
	if K<=0:
		print (i+1)
		break
