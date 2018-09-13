S=raw_input().strip()[::-1]

V=[]
cur=0
for c in S:
	if c=="+":
		cur+=1
	elif c=="-":
		cur-=1
	else:
		V.append(cur)

V.sort()
res = 0
for i in range(len(V)):
	if i < len(V)/2:
		res -= V[i]
	else:
		res += V[i]
print res
