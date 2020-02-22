import sys

N=input()
str=list(raw_input())
a={"1":0,"2":0,"3":0,"4":0}
for s in str:
	a[s] = a[s] + 1

print "%d %d"%(max(a.values()),min(a.values()))


