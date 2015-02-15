import sys
import re

E=list(raw_input().split(" "))
B=raw_input()
L=list(raw_input().split(" "))

mat=0
bo=0
for i in range(0,6):
	if L[i] in E:
		mat += 1
	if L[i] == B:
		bo += 1

if mat==6:
	print 1
elif mat==5 and bo>0:
	print 2
elif mat==5:
	print 3
elif mat==4:
	print 4
elif mat==3:
	print 5
else:
	print 0
