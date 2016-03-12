
N,K=map(int,raw_input().strip().split(" "))
W=[]
P=[]

def ok(v):
	V=[]
	for i in range(N):
		V.append([(P[i]-v)*W[i], i])
	V.sort()
	V.reverse()
	
	salt = water = 0
	for i in range(K):
		water += W[V[i][1]]
		salt += P[V[i][1]] * W[V[i][1]]
	
	if salt >= water * v:
		return 1
	else:
		return 0

for i in range(N):
	w,p=map(int,raw_input().strip().split(" "))
	W.append(w)
	P.append(p)

L = 0
R = 100.0
for i in range(200):
	M = (L+R)/2.0
	if ok(M):
		L = M
	else:
		R = M

print L

