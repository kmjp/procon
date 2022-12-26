
from decimal import *
getcontext().prec = 30

A,B,C=map(Decimal, input().split())


if A==0:
	if B==0:
		if C==0:
			print(-1)
		else:
			print(0)
	else:
		print(1)
		print(-C/B)
else:
	if A<0:
		A,B,C=-A,-B,-C
		
	D = B*B-4*A*C
	if D==0:
		R = -B/(2*A)
		print(1)
		print(R)
	elif D<0:
		print(0)
	else:
		R1 = -(B+D**Decimal(0.5))/(2*A)
		R2 = -(B-D**Decimal(0.5))/(2*A)
		print(2)
		print(R1)
		print(R2)
