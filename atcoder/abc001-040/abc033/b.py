N=input()
S=[]
P=[]
sum=0

for i in range(N):
	x,y=raw_input().strip().split(" ")
	S.append(x)
	P.append(int(y))
	sum += P[-1]

A="atcoder"
for i in range(N):
	if P[i]*2 > sum:
		A=S[i]

print A

