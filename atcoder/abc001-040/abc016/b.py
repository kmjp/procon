import sys
import math

A,B,C=map(int,raw_input().strip().split(" "))

if B==0:
	if A==C:
		print "?"
	else:
		print "!"
else:
	if A-B == C:
		print "-"
	elif A+B == C:
		print "+"
	else:
		print "!"
