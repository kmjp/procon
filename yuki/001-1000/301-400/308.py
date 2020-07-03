import sys
import math
import random

N=input()

def create_erato(n):
	div = [0]*(n+2)
	primes = []
	for i in range(2,n+1):
		if div[i] == 0:
			primes.append(i)
			for j in range(i,n+1,i):
				div[j] = i
	return (div,primes)

div = create_erato(105)[0]
vis=[0]*105

def ok(N,M):
	q=[1]
	while len(q) > 0:
		v = q[-1]
		q.pop()
		
		for t in (v-1,v+1,v-M,v+M):
			if v%M==1 and t==v-1:
				continue
			if v%M==0 and t==v+1:
				continue
			if t<=0 or t>N:
				continue
			if div[t]!=t and vis[t]<M:
				vis[t]=M
				q.append(t)
	
	if vis[N]==M:
		return 1
	return 0

def MillarRabin(v,loop):
	d = v-1
	s = 0
	while d%2==0:
		s += 1
		d /= 2
	
	for i in range(loop):
		a = random.randrange(0,v-2)+1
		r = pow(a,d,v)
		if r==1 or r==v-1:
			continue
		ng = 0
		for j in range(s):
			r = pow(r,2,v)
			if r == v-1:
				ng = 1
		if ng==0:
			return 0
	
	return 1


if N>=100:
	random.seed()
	for v in range(8,100,2):
		if div[v+1]!=v+1 and (N%v!=1 or MillarRabin(N-v,100)==0):
			print v
			break
else:
	for M in range(2,105):
		if ok(N,M):
			print M
			break


