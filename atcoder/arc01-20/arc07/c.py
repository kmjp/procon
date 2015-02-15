import sys

S=list(raw_input())
L=len(S)
v=0
for i in range(L):
	if S[i]=="o":
		v |= 1<<i

mi=1000
for par in range(1<<L):
	b=0
	t=0
	for i in range(L):
		if (par & (1<<i))>0:
			t += 1
			b |= (v<<i) | (v>>(L-i))
			
	if b & ((1<<L)-1) == ((1<<L)-1):
		mi=min(mi,t)

print(mi)




