import sys
import math

def func(t):
	return A*t+B*math.sin(C*t*math.pi)

A,B,C=map(int,raw_input().strip().split(" "))

L=R=0.0
i = 0
while 1:
	if func(i/1000.0)<=100 and func((i+1)/1000.0)>=100:
		L = i/1000.0
		R = (i+1)/1000.0
		break
	i += 1

for i in range(100):
	M = (L+R)/2.0
	if func(M) < 100:
		L = M
	else:
		R = M

print L
