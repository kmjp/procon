
def gcd(a, b):
	return a if b == 0 else gcd(b, a%b)

A,B=map(int,raw_input().strip().split(" "))
print gcd(A+B,A*B)

