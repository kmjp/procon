
N=input()
B=[]

def ok(v):
	D=[0]*N
	for (h,s) in B:
		if v < h:
			return False
		t = (v-h)/s
		if t < N:
			D[t] += 1
	
	x = 0
	for i in range(N):
		if x > i:
			return False
		x += D[i]
	return True

for i in range(N):
	h,s=map(int,raw_input().strip().split(" "))
	B.append((h,s))

ret = (1<<51)-1
for i in range(50,-1,-1):
	if ok(ret - (1<<i)):
		ret -= 1<<i

print ret


