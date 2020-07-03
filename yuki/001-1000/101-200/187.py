import sys
import math

def ext_gcd(p,q):
	if q==0:
		return (p,1,0)
	g,y,x = ext_gcd(q,p%q);
	y -= p/q*x
	return (g,x,y)

def cmt(a1,mo1,a2,mo2):
	g,x,y=ext_gcd(mo1,mo2)
	a1%=mo1
	a2%=mo2
	if a1%g != a2%g:
		return (-1,0)
	lcm=mo1*(mo2/g)
	return ((a1+((a2-a1)%lcm)*x%lcm*(mo1/g)) % lcm,lcm)

N=input()
P=[]
for i in range(N):
	P.append(map(int,raw_input().strip().split(" ")))

T=[P[0][0],P[0][1]]
for i in range(1,N):
	T2=cmt(T[0],T[1],P[i][0],P[i][1])
	if T2[0]<0:
		print -1
		sys.exit()
	T=[T2[0],T2[1]]

if T[0]==0:
	T[0]=T[1]

print T[0]%1000000007
