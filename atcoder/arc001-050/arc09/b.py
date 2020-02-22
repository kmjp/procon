import sys

B=map(int,raw_input().split(" "))
m1=range(0,10)
m2=range(0,10)
for i in range(0,10):
	m1[B[i]]=i
	m2[i]=B[i]

N=input()
A=[]
for i in range(0,N):
	c=input()
	v=0
	for d in range(0,10):
		v += m1[(c/(10**d))%10]*(10**d)
	A.append(v)

A.sort()
for i in A:
	v=0
	for d in range(0,10):
		v += m2[(i/(10**d))%10]*(10**d)
	print(v)
