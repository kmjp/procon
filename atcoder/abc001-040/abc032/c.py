
N,K=map(int,raw_input().strip().split(" "))
S=[]
P0 = 0

for i in range(N):
	S.append(input())
	if S[-1] == 0:
		P0 = 1

if P0==1:
	print N
	
else:
	ma = 0
	P = 1
	y = -1
	for x in range(N):
		while y+1 < N and P*S[y+1] <= K:
			y += 1
			P *= S[y]
		
		ma=max(ma,y-x+1)
		
		if y >= x:
			P /= S[x]
		else:
			y = x
	
	print ma
