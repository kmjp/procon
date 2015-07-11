import sys
import math

N=input()
B=[0]
C=[[0 for i in range(0)] for j in range(55)]

for i in range(N-1):
	B.append(input()-1)

for i in range(N-1,-1,-1):
	P = 1
	if len(C[i])>0:
		C[i].sort()
		P += C[i][0] + C[i][-1]
	
	if i==0:
		print P
	else:
		C[B[i]].append(P)

