import Queue

N,M,T=map(int,raw_input().strip().split(" "))
A=map(int,raw_input().strip().split(" "))
E = [[],[]];
D = [[1<<30]*N,[1<<30]*N];

for i in range(N):
	E[0].append([])
	E[1].append([])

for i in range(M):
	a,b,c=map(int,raw_input().strip().split(" "))
	E[0][a-1].append((b-1,c))
	E[1][b-1].append((a-1,c))


Q = Queue.PriorityQueue()
D[0][0] = D[1][0] = 0
Q.put((0,0))
Q.put((0,1000000))

while not Q.empty():
	r = Q.get()
	cost = r[0]
	cur = r[1]%1000000
	ph = r[1]/1000000
	if D[ph][cur] != cost:
		continue
	
	for e in E[ph][cur]:
		if D[ph][e[0]] > cost + e[1]:
			D[ph][e[0]] = cost + e[1]	
			Q.put((D[ph][e[0]], ph*1000000+e[0]))

ma = 0
for i in range(N):
	ma = max(ma, (T - (D[0][i] + D[1][i])) * A[i])

print ma
