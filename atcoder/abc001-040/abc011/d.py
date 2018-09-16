import sys
import math

C = [[0 for j in range(1002)] for i in range(1002)]

C[0][0]=1.0
for i in range(0,1001):
	for j in range(0,1001):
		C[i+1][j] += C[i][j]/2.0
		C[i+1][j+1] += C[i][j]/2.0

N,D=map(int,raw_input().split(' '))
X,Y=map(abs,map(int,raw_input().split(' ')))

xp = X/D
yp = Y/D

if (xp+yp)%2 != N%2 or X%D>0 or Y%D>0:
	print 0.0
	sys.exit()


ret = 0.0
for x1 in range(0,N+1):
	x2 = x1-xp
	y1 = yp+(N-x1-x2-yp)/2
	y2 = (N-x1-x2-yp)/2
	if x2<0 or y1<0 or y2<0:
		continue
	ret += C[N][x1]*C[N-x1][x2]*C[N-x1-x2][y1]*pow(0.5,2*N-(N+N-x1+N-x1-x2))

print ret

