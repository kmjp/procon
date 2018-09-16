import sys
import math

tx0,ty0,tx1,ty1,T,V=map(int,raw_input().strip().split(" "))
N=input()

for i in range(0,N):
	x,y=map(int,raw_input().strip().split(" "))
	if math.sqrt((x-tx0)*(x-tx0)+(y-ty0)*(y-ty0)) + math.sqrt((x-tx1)*(x-tx1)+(y-ty1)*(y-ty1)) <= T*V:
		print "YES"
		sys.exit(0)
print "NO"
