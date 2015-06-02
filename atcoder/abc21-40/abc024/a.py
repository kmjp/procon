A,B,C,K=map(int,raw_input().strip().split(" "))
S,T=map(int,raw_input().strip().split(" "))

F=A*S+B*T
if S+T >= K:
	F -= (S+T)*C
print F
