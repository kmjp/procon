import sys
import re

def inc(D):
	mm = [0,31,28,31,30,31,30,31,31,30,31,30,31]
	if D[0] % 4 == 0:
		mm[2] += 1
	if D[0] % 100 == 0:
		mm[2] -= 1
	if D[0] % 400 == 0:
		mm[2] += 1
	D[2] += 1
	if D[2] > mm[D[1]]:
		D[2] = 1
		D[1] += 1
	if D[1] > 12:
		D[0] += 1
		D[1] = 1
	return D

A=raw_input()
r=re.compile("(\d+)/(\d+)/(\d+)")
m=r.search(A)
da=[int(m.group(1)),int(m.group(2)),int(m.group(3))]

while da[0] % (da[1]*da[2]) > 0:
	da = inc(da)

print "%04d/%02d/%02d" % (da[0],da[1],da[2])



