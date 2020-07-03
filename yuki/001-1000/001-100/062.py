import sys
import fractions

W=H=D=MX=MY=HX=HY=VX=VY=0

def ext_gcd(p,q):
	if q==0:
		return (p,1,0)
	(g,y,x) = ext_gcd(q, p%q)
	return (g,x,y - (p//q)*x)

def calc(tx,ty):
	A = 2*W*VY
	B = -2*H*VX
	C = ty*VX-tx*VY+HX*VY-HY*VX
	
	g = fractions.gcd(A, -B)
	if C % g > 0:
		return False
	A /= g
	B /= g
	C /= g
	
	g,y,x=ext_gcd(B,A);
	
	m = C*y%A
	tv=(ty+2*H*m-HY)/VY;
	
	tv %= 2*H*A/VY;
	if tv<0:
		tv += 2*H*A/VY;
	return tv<=D

Q = input()
while Q > 0:
	Q -= 1
	W,H,D,MX,MY,HX,HY,VX,VY=map(int,raw_input().strip().split())
	
	if VX < 0:
		MX = W - MX
		HX = W - HX
		VX = -VX
	if VY < 0:
		MY = H - MY
		HY = H - HY
		VY = -VY
	
	if VX == 0:
		if MX==HX and ((MY>HY and (MY-HY)<=D*VY) or (MY<HY and (2*H-MY-HY)<=D*VY)):
			print "Hit"
		else:
			print "Miss"
		continue
	
	if VY == 0:
		if MY==HY and ((MX>HX and (MX-HX)<=D*VX) or (MX<HX and (2*W-MX-HX)<=D*VX)):
			print "Hit"
		else:
			print "Miss"
		continue
	
	g = fractions.gcd(VX, VY)
	D *= g
	VX /= g
	VY /= g
	
	if calc(MX,MY) or calc(2*W-MX,MY) or calc(MX,2*H-MY) or calc(2*W-MX,2*H-MY):
		print "Hit"
	else:
		print "Miss"


