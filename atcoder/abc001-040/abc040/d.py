
# UF
ufn = 101010
rank = [0]*ufn
cnt = [1]*ufn
par = []
for i in range(ufn):
	par.append(i)

def get(x):
	if par[x] != x:
		par[x] = get(par[x])
	return par[x]
	
def count(x):
	return cnt[get(x)]

def unite(x,y):
	x = get(x)
	y = get(y)
	if x == y:
		return x
	cnt[x] = cnt[y] = cnt[x] + cnt[y]
	if rank[x] > rank[y]:
		par[x] = y
		return y
	else:
		par[y] = x
		return x


P=[]
R=[]
for i in range(202020):
	P.append([])
	R.append([])
A=[]
B=[]
V=[]
ret=[0]*202020

N,M=map(int,raw_input().strip().split(" "))
for i in range(M):
	a,b,y=map(int,raw_input().strip().split(" "))
	A.append(a-1)
	B.append(b-1)
	R[y].append(i)

Q=input()
for i in range(Q):
	v,w=map(int,raw_input().strip().split(" "))
	V.append(v-1)
	P[w].append(i)

for i in range(202010,-1,-1):
	for p in P[i]:
		ret[p] = count(V[p])
	for r in R[i]:
		unite(A[r],B[r])

for i in range(Q):
	print ret[i]
