
from sets import Set

N=input()
A=map(int,raw_input().strip().split(" "))

S = Set()
for a in A:
	while a % 2 == 0:
		a /= 2
	S.add(a)

print len(S)

