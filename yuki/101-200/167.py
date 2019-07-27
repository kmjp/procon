import sys
import math

N=input()%10
M=input()

if M==0:
	print 1
else:
	M=M%4+4
	print (N**M)%10

