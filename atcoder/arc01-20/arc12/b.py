import sys

N,Va,Vb,L=map(float,raw_input().split(" "))

for i in range(int(N+0.1)):
	L *= Vb/Va
print(L)


