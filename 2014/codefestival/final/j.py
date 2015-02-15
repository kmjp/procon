
import sys
import fractions
A,B,K=map(int,raw_input().strip().split(' '))

def move(N):
	if N==1:
		return 1
	diff = 0
	if N*B/A != (N-1)*B/A:
		diff = 1
	return 2*(N + N*B/A - diff)

g=fractions.gcd(A,B)
A /= g
B /= g

if K==0:
	print 1
	sys.exit(0)

if A<B:
	A,B=B,A

pata = patb = 0
for i in range(40,-1,-1):
	if move(pata + (1<<i)) <= K:
		pata += 1<<i
	if move(patb + (1<<i))-2 <= K:
		patb += 1<<i

print min(pata+patb,A)+1


