
L=input()

def fib(L):
	if L<3:
		return 1
	v1=v2=a=b=c=1
	d=0
	L-=2
	while L:
		if L%2:
			v2,v1=a*v2+b*v1,c*v2+d*v1
		L /= 2
		bc=b*c
		a,b,c,d=a*a+bc,b*(a+d),c*(a+d),bc+d*d
	return v2


if L==2:
	print 3
	print "INF"
else:
	ret = fib(L)
	if L%2==0:
		ret -= fib(L/2)**2
	
	print L
	print ret

