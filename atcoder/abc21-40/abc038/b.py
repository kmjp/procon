A1,B1=map(int,raw_input().strip().split(" "))
A2,B2=map(int,raw_input().strip().split(" "))

if A1==A2 or A1==B2 or B1==A2 or B1==B2:
	print "YES"
else:
	print "NO"

