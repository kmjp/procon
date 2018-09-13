N=input()
S=[]
for i in range(N):
	S.append(raw_input())

for y in range(N):
	T=""
	for x in range(N):
		T += S[N-1-x][y]
	print T
