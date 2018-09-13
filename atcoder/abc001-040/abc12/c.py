import sys

N=input()
tot=0
for i in range(1,10):
	for j in range(1,10):
		tot+=i*j

for i in range(1,10):
	for j in range(1,10):
		if N+i*j == tot:
			print "%d x %d" % (i,j)


