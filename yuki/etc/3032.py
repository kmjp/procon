import sys
import math

N=input()
for i in range(N):
	A,B=map(int,raw_input().strip().split(" "))
	C=A-B
	
	if C != abs(C):
		print chr(60)
	elif -C == abs(-C):
		print "="
	else:
		print chr(62)
	


