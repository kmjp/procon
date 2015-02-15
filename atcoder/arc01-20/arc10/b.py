import sys

def day2int(M,D):
	MD=[31,29,31,30,31,30,31,31,30,31,30,31]
	d=D-1
	for i in range(0,M-1):
		d += MD[i]
	return d

B=[0] * 800
for i in range(100):
	if i*7 < 366:
		B[i*7]=1
	if i*7+6 < 366:
		B[i*7+6]=1

N=input()
for i in range(N):
	M,D=map(int,raw_input().split("/"))
	d = day2int(M,D)
	while B[d]==1:
		d+=1
	B[d]=1

ml=2
l=0
for i in range(366):
	l = (l + B[i]) * B[i]
	ml=max(l,ml)

print(ml)


