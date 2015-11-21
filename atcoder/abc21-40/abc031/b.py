L,H=map(int,raw_input().strip().split(" "))
N=input()

for i in range(N):
	A = input()
	
	if A>H:
		print -1
	elif A>=L:
		print 0
	else:
		print L-A

