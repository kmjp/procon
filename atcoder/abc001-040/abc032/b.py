
S=raw_input().strip()
K=input()

SS=set()
for i in range(len(S)):
	if i+K <= len(S):
		SS.add(S[i:(i+K)])

print len(SS)

