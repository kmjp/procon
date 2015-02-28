S=raw_input().strip()
V=[]

for s in S:
	if len(V)==0 or V[-1][0]!=s:
		V.append([s,1])
	else:
		V[-1][1] += 1

s=""
for v in V:
	s += "%s%d" % (v[0],v[1])
print s
