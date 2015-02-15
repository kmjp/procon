import sys

X,Y=map(int,raw_input().split("/"))

R=[]
for N in range(2*X/Y-5,2*X/Y+5):
	if N<=0:
		continue
	U=N*((N+1)*Y-2*X)
	D=2*Y
	if U%D>0:
		continue
	M=U/D
	if 1<=M<=N:
		R.append((N,M))

if len(R)==0:
	print("Impossible")
else:
	for i in R:
		print "%d %d"%(i[0],i[1])
	

