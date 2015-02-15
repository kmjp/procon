import sys

C=input()
M=[0,0,0]
for i in range(C):
	B=map(int,raw_input().split(" "))
	B.sort()
	M[0]=max(M[0],B[0])
	M[1]=max(M[1],B[1])
	M[2]=max(M[2],B[2])

print(M[0]*M[1]*M[2])
