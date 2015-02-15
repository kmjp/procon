import sys

P = [1.0]
C = [[0.0 for j in range(106)] for i in range(106)]
for i in range(0,105):
	C[i][0]=1.0
	for j in range(1,i+1):
		C[i][j] = C[i-1][j-1] + C[i-1][j]
	P.append(P[-1]*(i+1.0))

N=input()
S=[]
for i in range(0,N):
	S.append(input())

ret = 0.0
for x in range(0,N):
	mul = 0
	for y in range(0,N):
		if x != y and (S[x] % S[y] == 0):
			mul += 1
	for z in range(0,mul+1,2):
		ret += C[mul][z] * P[mul-z] * P[z] / P[mul+1]

print ret


