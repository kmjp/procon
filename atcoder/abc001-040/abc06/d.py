import sys
import bisect

N=input()
LIS = []

for x in range(0,N):
	y = input()
	z = bisect.bisect_left(LIS, y)
	if z >= len(LIS):
		LIS.append(y)
	else:
		LIS[z]=y

print N-len(LIS)


