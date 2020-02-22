import sys

F,L=raw_input().strip().split(" ")
N=input()
W=[F,L]
for i in range(N):
	W.append(raw_input().strip())

W=list(set(W))
N=len(W)
tl=len(F)
fp=lp=0

for x in range(N):
	if W[x]==F:
		fp=x
	if W[x]==L:
		lp=x

if fp==lp:
	print(0)
	print(F)
	print(L)
	exit()
	
C=[999999 for i in range(N)]
P=[0 for i in range(N)]
C[fp]=0

Q=[fp]
qi=0

while qi < len(Q):
	cur=Q[qi]
	for i in range(N):
		if C[i]>C[cur]+1:
			v=0
			for z in range(tl):
				if W[cur][z]!=W[i][z]:
					v += 1
					if v>1:
						break
			if v==1:
				C[i]=C[cur]+1
				P[i]=cur
				Q.append(i)
	qi += 1

if C[lp]==999999:
	print(-1)
else:
	print(C[lp]-1)
	WL=[]
	i = lp
	while i != fp:
		WL.append(W[i])
		i=P[i]
	WL.reverse()
	print(F)
	for w in WL:
		print(w)

