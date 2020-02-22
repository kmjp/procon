import sys
 
N=input()
r=0
for i in range(0,N):
	A,B=map(int,raw_input().split(" "))
	r += A*B

r = r + r/20
print(r)

