import sys

N=input()
X=[]
Y=[]
for i in range(0,N):
	x,y=map(int,raw_input().strip().split(" "))
	X.append(x)
	Y.append(y)

r=0
for x in range(0,N):
	for y in range(x+1,N):
		for z in range(y+1,N):
			ret = (Y[y]-Y[x])*(X[z]-X[x])-(X[y]-X[x])*(Y[z]-Y[x])
			if ret != 0 and ret % 2 == 0:
				r = r + 1

print r

