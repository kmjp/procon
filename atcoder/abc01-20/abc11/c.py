import sys

N=input()
NG1=input()
NG2=input()
NG3=input()

if N==NG1 or N==NG2 or N==NG3:
	print "NO"
	sys.exit(0)

for i in range(0,100):
	j=min(3,N)
	while j>0 and (N-j==NG1 or N-j==NG2 or N-j==NG3):
		j-=1
	N-=j

if N==0:
	print "YES"
else:
	print "NO"

