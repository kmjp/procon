import sys
import math

M,D=map(int,raw_input().strip().split(" "))

if M % D == 0:
	print "YES"
else:
	print "NO"
