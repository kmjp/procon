import sys

N,K=map(int,raw_input().strip().split(" "))
S=raw_input().strip()
C={}

def okok(ind,num):
	C2 = C.copy()
	for i in range(ind,N):
		if C2[S[i]] > 0:
			C2[S[i]] -= 1
		else:
			num -= 1
	return num >= 0

for c in range(ord('a'),ord('z')+1):
	C[chr(c)] = 0

for c in S:
	C[c] += 1

T=''
for i in range(0,N):
	for j in range(ord('a'),ord('z')+1):
		c=chr(j)
		if C[c] > 0:
			C[c] -= 1
			if S[i]!=c:
				K -= 1
			if okok(i+1,K):
				T += c
				break
			if S[i]!=c:
				K += 1
			C[c] += 1

print T
