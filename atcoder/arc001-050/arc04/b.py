import sys

N=input()
tot=0
ma=0

for i in range(0,N):
	a=input()
	tot += a
	ma = max(ma, a)

print(tot)

if ma > tot - ma :
	print(ma-(tot-ma))
else:
	print(0)

