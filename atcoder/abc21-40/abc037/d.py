H,W=map(int,raw_input().strip().split(" "))
S = []
dp = []
mo = 1000000007
cand = []

for y in range(H):
	S.append(map(int,raw_input().strip().split(" ")))
	dp.append([1]*W)
	for x in range(W):
		cand.append((S[y][x],(y,x)))

ret = 0
for e in sorted(cand):
	cy,cx = e[1]
	ret += dp[cy][cx]
	for d in ((-1,0),(0,-1),(1,0),(0,1)):
		ty = cy+d[0]
		tx = cx+d[1]
		if tx >= 0 and ty>=0 and tx<W and ty<H and S[ty][tx] > S[cy][cx]:
			dp[ty][tx] += dp[cy][cx] % mo

print ret % mo
