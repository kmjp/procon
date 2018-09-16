import sys

A,B=map(int,raw_input().strip().split(" "))

def dodo(v):
	if v<=0:
		return 0
	if v>=1000000000000000000:
		v -= 1
	
	vv = 1
	ld = 1
	ret = 0
	
	while vv*10 <= v:
		vv *= 10
		ld *= 8
	
	for i in range(0,int(v/vv)):
		ret += vv
		if i!=4 and i!=9:
			ret -= ld
	
	if int(v/vv)==4 or int(v/vv)==9:
		return ret + (v - int(v/vv)*vv + 1)
	else:
		return ret + dodo(v - int(v/vv)*vv)

print dodo(B)-dodo(A-1)


