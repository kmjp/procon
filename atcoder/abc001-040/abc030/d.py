
N,A=map(int,raw_input().strip().split(" "))
K=input()
B=map(int,raw_input().strip().split(" "))

P=[-1]*100010

pat=0
C=A
P[C]=0

while 1:
	if K<=0:
		break
	K-=1
	C=B[C-1]
	pat += 1
	if P[C]>=0:
		lp=pat-P[C]
		K %= lp
	P[C]=pat

print C
