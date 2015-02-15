import sys

A,B=map(int,raw_input().strip().split())

def leap(v):
	return (v/4)-(v/100)+(v/400)

print leap(B)-leap(A-1)
