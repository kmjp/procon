import sys

N,M=map(int,raw_input().strip().split(" "))

for x in range(0,N+1):
	z = (M-x*2)-3*(N-x)
	y = N-x-z
	if y >= 0 and z >= 0:
		print "%d %d %d" % (x,y,z)
		sys.exit()

print "-1 -1 -1"
