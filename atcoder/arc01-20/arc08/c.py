import sys
import Queue as queue

N=input()
A=[]
for i in range(N):
	A.append([map(int,raw_input().split(" ")),999999999999999.0])
	
A[0][1]=0.0
q=queue.PriorityQueue()
q.put((0.0,0))
vis=[0 for i in range(1001)]

while not q.empty():
	ct,cur=q.get()
	if vis[cur]>0:
		continue
	vis[cur]=1
	
	for i in range(N):
		if vis[i]>0:
			continue
		nd = A[cur][1] + (((A[cur][0][0]-A[i][0][0])**2+(A[cur][0][1]-A[i][0][1])**2)**0.5) / min(A[cur][0][2],A[i][0][3])
		if nd < A[i][1]:
			A[i][1]=nd
			q.put((nd,i))

A.sort(lambda x,y: cmp(x[1],y[1]))
ma=0.0
for i in range(1,N):
	ma=max(ma, A[i][1]+(N-1-i))

print(ma)


