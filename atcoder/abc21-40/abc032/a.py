def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a%b)

A=input()
B=input()
N=input()

X=A*B/gcd(A,B)

V=0
while V < N:
	V += X

print V
