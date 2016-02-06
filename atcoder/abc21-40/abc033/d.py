import math

# ’FPython‚Å‚ÍTLE‚Ì‚½‚ß•”•ª“_‚µ‚©æ‚ê‚Ü‚¹‚ñB


N=input()
X=[]
Y=[]

for i in range(N):
	x,y=map(int,raw_input().strip().split(" "))
	X.append(x)
	Y.append(y)

eps = 1e-9
A=B=C=0
for i in range(N):
	P = []
	for j in range(N):
		if i!=j:
			P.append(math.atan2(Y[j]-Y[i],X[j]-X[i]))
	
	P.sort()
	for j in range(N-1):
		P.append(P[j]+2*math.pi)
	
	y=z=0
	for x in range(N-1):
		while P[y]-P[x] < math.pi/2-eps:
			y+=1
		while P[z]-P[x] < math.pi+eps:
			z+=1
		if math.fabs(P[y]-P[x]-math.pi/2)<2*eps:
			B += 1
			y += 1
		C += z-y

A=N*(N-1)*(N-2)/6-B-C

print A,B,C
