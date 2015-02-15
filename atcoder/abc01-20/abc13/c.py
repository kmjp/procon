import sys

N,H=map(int,raw_input().strip().split())
A,B,C,D,E=map(int,raw_input().strip().split())

ret = 1<<60
for TA in range(0,N+1):
	LD = N-TA
	hang = H+TA*B
	
	if hang > LD*E:
		TB=0
	else:
		TB=max(0,(LD*E-hang)/(D+E)+1)
	
	ret = min(ret, TA*A+TB*C)

print ret
