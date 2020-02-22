import sys

N=input()
W=[]
for i in range(N):
	W.append(raw_input().strip())

S=set([W[0]])

for i in range(1,N):
	if (W[i] in S) or (W[i][0]!=W[i-1][-1]):
		if i%2==0:
			print("LOSE")
		else:
			print("WIN")
		exit()
	S.add(W[i])

print("DRAW")

