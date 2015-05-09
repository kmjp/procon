
R,C,K = map(int,raw_input().strip().split(" "))
N = input()

NR = [0]*R
NC = [0]*C
cand = []

for i in range(N):
	r,c=map(int,raw_input().strip().split(" "))
	cand.append((r-1,c-1))
	NR[r-1] += 1
	NC[c-1] += 1

CS = [0]*101000
for nc in NC:
	CS[nc] += 1

ret = 0
for nr in NR:
	left = K - nr
	if left >= 0:
		ret += CS[left]

for (r,c) in cand:
	if NR[r] + NC[c] == K:
		ret -= 1
	if NR[r] + NC[c] == K+1:
		ret += 1

print ret
