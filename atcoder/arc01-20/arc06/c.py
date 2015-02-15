import sys

N=input()
Q=[]

for i in range(N):
	w=input()
	ok=0
	for j in range(len(Q)):
		if w<=Q[j]:
			ok=1
			Q[j]=w
			break
	if ok==0:
		Q.append(w)
	Q.sort()

print(len(Q))
