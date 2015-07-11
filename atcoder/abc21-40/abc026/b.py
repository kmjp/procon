import math

N=input()
R=[]
for i in range(N):
	R.append(input())

R.sort()
R.reverse()

ret=0
for i in range(len(R)):
	if i & 1:
		ret -= R[i]*R[i]*math.pi
	else:
		ret += R[i]*R[i]*math.pi

print ret
