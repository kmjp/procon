import sys

K,M=map(int,raw_input().strip().split(" "))
A=map(int,raw_input().strip().split(" "))
C=map(int,raw_input().strip().split(" "))

def powmat(p,G):
	A = G[:]
	
	R = [0] * (K*K)
	H = [0] * (K*K)
	for j in range(0,K):
		R[j*K+j] = (1<<32)-1
	
	while p>0:
		if p%2 > 0:
			for x in range(0,K):
				for y in range(0,K):
					H[x*K+y] = 0
					for z in range(0,K):
						H[x*K+y] ^= R[x*K+z]&A[z*K+y]
			R = H[:]
		
		for x in range(0,K):
			for y in range(0,K):
				H[x*K+y] = 0
				for z in range(0,K):
					H[x*K+y] ^= A[x*K+z]&A[z*K+y]
		A = H[:]
		p /= 2
	return R

G = [0] * (K*K)

for j in range(0,K-1):
	G[(j+1)*K+j] = (1<<32)-1

for j in range(0,K):
	G[j] = C[j]

G2 = powmat(M-1,G)

ret = 0
for j in range(0,K):
	ret ^= A[j] & G2[(K-1)*K + K-1-j]

print ret

