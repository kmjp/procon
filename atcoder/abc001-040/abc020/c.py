
import Queue as queue

H,W,T=map(int,raw_input().strip().split(" "))
S=[]
sy=sx=gy=gx=0

def ok(v):
	dist = [[(1<<60) for i in range(W)] for j in range(H)]
	q = queue.PriorityQueue()
	
	dist[sy][sx] = 0
	q.put((0,sy*100+sx))
	
	dd=[1,0,-1,0]
	while not q.empty():
		e = q.get()
		y = e[1] / 100
		x = e[1] % 100
		if e[0] != dist[y][x]:
			continue
		
		for i in range(4):
			ty = y + dd[i]
			tx = x + dd[i^1]
			
			if tx >= 0 and tx < W and ty >= 0 and ty < H:
				co = dist[y][x]
				if S[ty][tx] == '#':
					co += v
				else:
					co += 1
				
				if co < dist[ty][tx]:
					dist[ty][tx] = co
					q.put((co,ty*100+tx))
	
	if dist[gy][gx] <= T:
		return 1
	return 0


for y in range(H):
	S.append(raw_input().strip())
	for x in range(W):
		if S[y][x]=='S':
			S[y]=S[y][0:x]+'.'+S[y][x+1:]
			sy = y
			sx = x
		
		if S[y][x]=='G':
			S[y]=S[y][0:x]+'.'+S[y][x+1:]
			gy = y
			gx = x

ret = 0
for i in range(40,-1,-1):
	if ok(ret + (1<<i)):
		ret += 1<<i

print ret
