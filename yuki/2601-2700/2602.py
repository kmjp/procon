from fractions import Fraction
import sys
import math

Q=int(input())
X1,Y1,X2,Y2,X3,Y3=map(Fraction,input().strip().split(" "))
CX=-100000

for i in range(3) :
	if (Y2-Y1)*(Y2-Y1)+(X2-X1)*(X2-X1)+(Y3-Y1)*(Y3-Y1)+(X3-X1)*(X3-X1) <= (Y3-Y2)*(Y3-Y2)+(X3-X2)*(X3-X2):
		CX=(X2+X3)/2
		CY=(Y2+Y3)/2
		break
	X1,X2,X3=X2,X3,X1
	Y1,Y2,Y3=Y2,Y3,Y1

if CX == -100000:
	CX = ((X1*X1+Y1*Y1)*(Y2-Y3)+(X2*X2+Y2*Y2)*(Y3-Y1)+(X3*X3+Y3*Y3)*(Y1-Y2))/(2*((Y2-Y3)*(X1-X2)-(Y1-Y2)*(X2-X3)))
	CY = ((X1*X1+Y1*Y1)*(X2-X3)+(X2*X2+Y2*Y2)*(X3-X1)+(X3*X3+Y3*Y3)*(X1-X2))/(2*((X2-X3)*(Y1-Y2)-(X1-X2)*(Y2-Y3)))

R = (X2-CX)*(X2-CX)+(Y2-CY)*(Y2-CY)
for i in range(Q):
	X,Y=map(Fraction,input().strip().split(" "))
	X-=CX
	Y-=CY
	if X*X+Y*Y <= R:
		print("Yes")
	else:
		print("No")

