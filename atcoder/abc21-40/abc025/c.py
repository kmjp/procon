import sys
import math

B=[[0 for i in range(3)] for j in range(3)]
C=[[0 for i in range(3)] for j in range(3)]
T=[0 for i in range(9)]
memo={}



def dodo(turn):
	st=""
	for i in range(9):
		st += chr(ord('0')+T[i])
	if st in memo:
		return memo[st]
	
	p = [-1,-1]
	did = 0
	for y in range(3):
		for x in range(3):
			if T[y*3+x]!=0:
				continue
			
			did = 1
			T[y*3+x] = turn
			res = dodo(3-turn)
			T[y*3+x] = 0
			
			if res[turn-1] > p[turn-1]:
				p=res
	
	if did == 0:
		p = [0,0]
		for y in range(2):
			for x in range(3):
				if T[y*3+x]==T[y*3+x+3]:
					p[0] += B[y][x]
				else:
					p[1] += B[y][x]
		
		for y in range(3):
			for x in range(2):
				if T[y*3+x]==T[y*3+x+1]:
					p[0] += C[y][x]
				else:
					p[1] += C[y][x]
					
	memo[st]=p
	return p


B[0][0],B[0][1],B[0][2]=map(int,raw_input().strip().split(" "))
B[1][0],B[1][1],B[1][2]=map(int,raw_input().strip().split(" "))
C[0][0],C[0][1]=map(int,raw_input().strip().split(" "))
C[1][0],C[1][1]=map(int,raw_input().strip().split(" "))
C[2][0],C[2][1]=map(int,raw_input().strip().split(" "))

p=dodo(1)
print p[0]
print p[1]
