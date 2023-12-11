import sys
import math

N=int(input())

fact = [1]
for i in range(1,255):
	fact.append(fact[-1]*i)

def get(v):
	alive = [1]*N
	ret = []
	for i in range(N,0,-1):
		x = v // fact[i-1] + 1
		v %= fact[i-1]
		for a in range(N):
			if alive[a]==1:
				x -= 1
				if x==0:
					alive[a]=0
					ret.append(str(a+1))
					break
	assert len(ret)==N
	return ret

L=0
R=fact[N]
while L+1<R:
	M=(L+R)//2
	
	arr = get(M)
	print("? "+" ".join(arr))
	ret=int(input())
	if ret==1:
		L=M
	else:
		R=M


arr = get(L)
print("! "+" ".join(arr))





