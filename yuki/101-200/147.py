import sys
import math

def matmult(A,B):
	n=len(A)
	C=[[0 for i in range(n)] for j in range(n)]
	C[0][0]=(A[0][0]*B[0][0]+A[0][1]*B[1][0])%mo
	C[0][1]=(A[0][0]*B[0][1]+A[0][1]*B[1][1])%mo
	C[1][0]=(A[1][0]*B[0][0]+A[1][1]*B[1][0])%mo
	C[1][1]=(A[1][0]*B[0][1]+A[1][1]*B[1][1])%mo
	
	return list(C)

def matpow(A,p):
	n=len(A)
	A=list(A)
	R=[[0 for i in range(n)] for j in range(n)]
	for i in range(n):
		R[i][i]=1
	while p:
		if p%2:
			R = matmult(A,R)
		A=matmult(A,A)
		p >>= 1
	return R

def pat(c):
	A=[[1,1],[1,0]]
	B=matpow(A,c-1)
	return (B[0][0]+B[0][1]+B[1][0]+B[1][1])%mo

N=input()
ret = 1
mo=1000000007

for i in range(N):
	C,D=map(int,raw_input().strip().split(" "))
	if D>mo-1:
		D %= mo-1
	ret = ret * pow(pat(C),D,mo) % mo

print ret 

