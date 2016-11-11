import sys
import math

A,B=map(int,raw_input().strip().split(" "))
if A+B>A*B:
	print "S"
elif A+B<A*B:
	print "P"
else:
	print "E"
