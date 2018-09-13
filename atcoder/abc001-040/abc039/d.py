H,W=map(int,raw_input().strip().split(" "))
S = []
T = []
G = []

for y in range(H):
	S.append(list(raw_input().strip()))
	T.append(["#"]*W)
	G.append(["."]*W)

for y in range(H):
	for x in range(W):
		for tx in range(x-1,x+2):
			for ty in range(y-1,y+2):
				if tx >= 0 and tx < W and ty >= 0 and ty < H and S[y][x]==".":
					T[ty][tx] = "."

for y in range(H):
	for x in range(W):
		for tx in range(x-1,x+2):
			for ty in range(y-1,y+2):
				if tx >= 0 and tx < W and ty >= 0 and ty < H and T[y][x]=="#":
					G[ty][tx] = "#"

if S != G:
	print "impossible"
else:
	print "possible"
	for t in T:
		print "".join(t)

