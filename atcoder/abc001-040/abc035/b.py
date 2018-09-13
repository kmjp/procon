
S=raw_input()
T=input()

X=Y=P=0
for c in S:
	if c == 'L':
		X-=1
	if c == 'R':
		X+=1
	if c == 'U':
		Y-=1
	if c == 'D':
		Y+=1
	if c == '?':
		P+=1

D = abs(X) + abs(Y)

if T == 1:
	print D+P
else:
	if P > D:
		print (P-D)&1
	else:
		print D-P
