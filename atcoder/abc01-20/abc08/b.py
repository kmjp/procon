import sys

N=input()
M={}

for i in range(0,N):
	S=raw_input().strip()
	M[S] = M.get(S,0) + 1

ma = 0
r = ""
for k in M.keys():
	if M[k] > ma:
		ma = M[k]
		r = k
print r

