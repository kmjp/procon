import sys

A,B=map(int,raw_input().split(" "))
mi=999
for x10 in range(-10,10):
	for x5 in range(-10,10):
		mi=min(mi,abs(x10)+abs(x5)+abs(A+x10*10+x5*5-B))

print mi



