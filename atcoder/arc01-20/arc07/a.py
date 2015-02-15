import sys
 
A=raw_input()
B=raw_input()
 
C=''
for c in B:
	if c != A:
		C+=c
 
print(C)
