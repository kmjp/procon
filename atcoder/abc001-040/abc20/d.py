import math

mo = 1000000007

def enumdiv(n):
	S=[]
	i = 1
	while i*i <= n:
		if i*i > n:
			break
		if n % i == 0:
			S.append(i)
			if i*i != n:
				S.append(n/i)
		i += 1
	
	S.sort()
	return S

def enumpfactor(n):
	S=[]
	i = 2
	while i*i <= n:
		if n % i == 0:
			S.append(i)
			while n % i == 0:
				n /= i
		i += 1
	
	if n > 1:
		S.append(n)
	return S

def dodo(n,k):
	v=0
	F = enumpfactor(k)
	for mask in range(0,1<<len(F)):
		sgn = 1
		mul = 1
		for i in range(0,len(F)):
			if mask & (1<<i):
				sgn = -sgn
				mul *= F[i]
		
		v += sgn * mul * ((n/mul)*(n/mul+1)/2) % mo
	
	return v % mo


N,K=map(int,raw_input().strip().split(" "))

P = enumdiv(K)
ret = 0
for r in P:
	ret += K * dodo(N/r, K/r) % mo

print ret % mo
