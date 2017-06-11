import sys
import math



T=input()
while T>0:
	T-=1
	D=D2=input()
	
	if D==0:
		print 1
	else:
		(best,hoge)=(0,10**18)
		while 1:
			D += 10**9
			#print D,D*D
			if D*D>10**27:
				break
			left = D*D % (10**18)
			if 10**18-left < hoge:
				cand = 1+D*D/(10**18)
				best = cand
				hoge = 10**18-left
		
		D=D2+1
		while 1:
			D += 10**9
			if D*D>10**27:
				break
			left = D*D % (10**18)
			if left < hoge:
				cand = D*D/(10**18)
				best = cand
				hoge = left
		print best
	
	
