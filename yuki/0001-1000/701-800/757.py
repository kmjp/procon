

def Sn(n):
	bn = B**n
	return n*bn - (bn-1)/(B-1)

B=int(raw_input())
C=raw_input().strip()
D=0
for c in C:
	D=D*B+(ord(c)-ord('0'))

D-=1
L=0
for i in range(16,-1,-1):
	if Sn(L+(1<<i))<=D:
		L += 1<<i

D -= Sn(L)
L += 1

mo = D % L
D = (B**(L-1)) + D/L

D /= B**(L-1-mo)
print str(D%B)
