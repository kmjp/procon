
N,A,B=map(int,raw_input().strip().split(" "))
X=0

for i in range(N):
	S,DD=raw_input().strip().split(" ")
	D=min(B,max(int(DD),A))
	
	if S == 'East':
		X += D
	else:
		X -= D

if X==0:
	print 0
elif X > 0:
	print "East %d" % X;
elif X < 0:
	print "West %d" % -X;
