import sys

N = input()
D = [0]*1000005

for i in range(0,N):
	x,y=map(int,raw_input().strip().split())
	D[x] += 1
	D[y+1] -= 1

ma = cd = 0
for i in range(0,1000002):
	cd += D[i]
	ma = max(ma, cd)

print ma


