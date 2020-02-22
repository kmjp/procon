import sys

Y=input()
R="NO"
if Y % 4 == 0:
	R="YES"
if Y % 100 == 0:
	R="NO"
if Y % 400 == 0:
	R="YES"

print(R)

