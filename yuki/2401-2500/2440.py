import sys
import math

def floor_sum(N,M,A,B):
	# sum(i=0...N-1) floor((A*i+B)/M)
	
	ret=0
	if B>=M:
		ret+=N*(B//M)
		B%=M;

	if A>=M:
		ret+=N*(N-1)//2*(A//M)
		A%=M
	
	Y=(A*N+B)//M
	if Y==0:
		return ret
	
	X=Y*M-B
	ret+=(N-(X+A-1)//A)*Y
	ret+=floor_sum(Y,A,M,(A-X%A)%A)
	return ret



T=int(input())
while T > 0:
	T-=1
	N,D,M,S=map(int,input().strip().split(" "))
	
	a=D*M
	b=1<<S
	
	if a==b:
		R=N
	else:
		R=min(N,D*b//abs(a-b))
	
	C=floor_sum(R+1,D,1,0)-floor_sum(R+1,b,M,0)
	R=R-abs(C)

	print(R)

