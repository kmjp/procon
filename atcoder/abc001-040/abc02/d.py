import sys

ma=[[0 for j in range(12)] for i in range(12)]
N,M=map(int,raw_input().strip().split(" "))

for i in range(0,M):
	x,y=map(int,raw_input().strip().split(" "))
	ma[x-1][y-1]=ma[y-1][x-1]=1

re=0
for mask in range(0,1<<N):
	bi=0
	ng =0
	for x in range(0,N):
		if (mask & (1<<x)) == 0:
			continue
		bi += 1
		
		for y in range(0,N):
			if x==y:
				continue
			if (mask & (1<<y)) == 0:
				continue
			if ma[x][y]==0:
				ng = 1
	
	if ng==0 and bi > re:
		re = bi

print re
