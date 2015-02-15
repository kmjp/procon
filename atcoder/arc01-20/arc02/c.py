import sys

def cnt(C,L,R):
	c=0
	i=0
	while i < len(C):
		c += 1
		if i==len(C)-1:
			break
		
		if C[i:i+2]==L or C[i:i+2]==R:
			i += 2
		else:
			i += 1
	return c

N=input()
C=raw_input()

mc=N
for L1 in ["A","B","X","Y"]:
	for L2 in ["A","B","X","Y"]:
		for R1 in ["A","B","X","Y"]:
			for R2 in ["A","B","X","Y"]:
				L=L1+L2
				R=R1+R2
				mc=min(mc,cnt(C,L,R))

print(mc)
