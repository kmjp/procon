import sys
import math

def dsum(P):
	tx=ty=0
	
	for x,y in P:
		tx += 1.0*x
		ty += 1.0*y
	tx /= len(P)
	ty /= len(P)
	
	tl = 0
	for x,y in P:
		x -= tx
		y -= ty
		tl += (x*x+y*y) ** 0.5
	
	return tl

N=input()
TL=[]

for i in range(2):
	P = []
	for j in range(N):
		P.append(map(int,raw_input().strip().split(" ")))
	TL.append(dsum(P))

print TL[1]/TL[0]
