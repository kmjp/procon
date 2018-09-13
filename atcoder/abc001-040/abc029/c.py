N=input()

S=[]
S.append([""])

for i in range(8):
	S.append([])
	for s in S[i]:
		S[i+1].append(s+"a")
		S[i+1].append(s+"b")
		S[i+1].append(s+"c")

for s in S[N]:
	print s
