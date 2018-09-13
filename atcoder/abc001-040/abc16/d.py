import sys
import math

def test(X1,Y1,X2,Y2):
	x1 = X1-MX1
	x2 = X2-MX1
	x3 = MX2-MX1
	y1 = Y1-MY1
	y2 = Y2-MY1
	y3 = MY2-MY1
	
	if (y3*x1-x3*y1)*(y3*x2-x3*y2)>=0:
		return 0
	
	x1=MX1-X1
	x2=MX2-X1
	x3=X2-X1
	y1=MY1-Y1
	y2=MY2-Y1
	y3=Y2-Y1
	
	if (y3*x1-x3*y1)*(y3*x2-x3*y2)>=0:
		return 0
	return 1


MX1,MY1,MX2,MY2=map(int,raw_input().strip().split(" "))

N=input()
X=[]
Y=[]
for i in range(N):
	x,y=map(int,raw_input().strip().split(" "))
	X.append(x)
	Y.append(y)

cnt = 0
for i in range(N):
	cnt += test(X[i], Y[i], X[(i+1)%N], Y[(i+1)%N])

print (1+cnt/2)

