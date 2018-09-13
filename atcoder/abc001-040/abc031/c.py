N=input()
A=map(int,raw_input().strip().split(" "))

ma = -5000
for x in range(N):
	maxa = maxb = -5000
	
	for y in range(N):
		if x == y:
			continue
		V = [0,0]
		i = 0
		for z in range(N):
			if (x-z)*(y-z) <= 0:
				V[i] += A[z]
				i ^= 1
		
		if V[1] > maxb:
			maxa,maxb = V
	
	ma = max(ma,maxa)

print ma
