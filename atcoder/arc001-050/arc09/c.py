import sys

N,K=map(int,raw_input().split(" "))
m=1777777777

def comb(p,q):
	r=1
	rr=1
	for v in range(0,q):
		r = (r*(p-v)) % m
		rr = (rr*(v+1)) % m
	
	return ((r*pow(rr,m-2,m)) % m)

P=comb(N,K)
pat=[0,0,1]
for i in range(3,K+1):
	pat.append((pat[i-1]*(i-1) + (i-1)*pat[i-2])%m)

P=(P*pat[K])%m
print(P)



