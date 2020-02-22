import sys

N=input()
S=raw_input()

t=0
for i in range(0,N):
	if S[i] != 'F':
		t += ord('E')-ord(S[i])

print float(t)/N
