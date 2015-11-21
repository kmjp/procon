
K,N=map(int,raw_input().strip().split(" "))
D = []

for i in range(N):
	v,w=raw_input().strip().split(" ")
	S=[]
	for c in v:
		S.append(ord(c)-ord('1'))
	D.append((S,w))

fact = [1]
for i in range(10):
	fact.append(fact[-1]*3)

for mask in range(fact[K]):
	lenp = []
	R = [""]*K
	
	for i in range(K):
		lenp.append(mask/fact[i]%3+1)
	ok = 1
	
	for v,w in D:
		tlen = 0
		for r in v:
			tlen += lenp[r]
		
		if tlen != len(w):
			ok = 0
			break
		
		pos = 0
		for r in v:
			s = w[pos:pos+lenp[r]]
			
			if R[r] == "":
				R[r] = s
			elif R[r] != s:
				ok = 0
				break
			pos += lenp[r]
	
	if ok:
		for r in R:
			print r
		break

