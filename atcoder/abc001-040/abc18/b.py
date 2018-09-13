import sys
import math

S=raw_input()
N=input()

while N>0:
	N-=1
	x,y=map(int,raw_input().strip().split(" "))
	s1=S[0:x-1]
	s2=S[x-1:y]
	s3=S[y:]
	S=s1+s2[::-1]+s3

print S

