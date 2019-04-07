import sys
import math

T=int(input())

for t in range(T):
	N,L=list(map(int,input().strip().split(" ")))
	A=list(map(int,input().strip().split(" ")))
	
	P=set()
	for i in range(len(A)-1):
		g = math.gcd(A[i],A[i+1])
		if g!=A[i]:
			P.add(int(g))
			h=g
			for j in range(i+1,L):
				h=int(A[j]/h)
				P.add(h)
			h=g
			for j in range(i,-1,-1):
				h=int(A[j]/h)
				P.add(h)
			break
	for a in A:
		b = int((a+0.1)**0.5)
		if b*b==a:
			P.add(b)
	for i in range(100):
		for p in P:
			for a in A:
				if a%p==0:
					P.add(a/p)
	
	P=sorted(list(P))
	rev={}
	for i in range(len(P)):
		rev[P[i]]=i
	
	R=""
	for i in range(26):
		C=chr(ord('A')+i)
		cur=P[i]
		for j in range(len(A)):
			if A[j]%cur > 0:
				break
			cur=int(A[j]/cur)
			if cur not in rev:
				break
			C+=chr(ord('A')+rev[cur])
		if len(C)==L+1:
			R=C
	print("Case #%d: %s" % (t+1,R))
