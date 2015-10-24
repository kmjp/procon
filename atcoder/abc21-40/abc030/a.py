
A,B,C,D=map(int,raw_input().strip().split(" "))

if B*C<A*D:
	print "AOKI"
elif B*C>A*D:
	print "TAKAHASHI"
else:
	print "DRAW"
