import sys
 
m,n,N=map(int,raw_input().split(" "))
T=N
while N>=m:
	N-=(m-n)
	T+=n

print(T)


