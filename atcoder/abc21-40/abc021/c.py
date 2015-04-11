N=input()
A,B=map(int,raw_input().strip().split(" "))
A -= 1
B -= 1


mat=[[101 for i in range(101)] for j in range(101)]

for i in range(N+1):
	mat[i][i]=0

M=input()
for i in range(M):
	x,y=map(int,raw_input().strip().split(" "))
	mat[x-1][y-1] = mat[y-1][x-1] = 1

for i in range(N):
	for x in range(N):
		for y in range(N):
			mat[x][y] = min(mat[x][y], mat[x][i] + mat[i][y])

mo = 1000000007
num=[0] * 101
num[A] = 1
for i in range(0,N):
	for cur in range(0,N):
		if mat[A][cur] != i:
			continue
		for tar in range(0,N):
			if mat[A][tar]==i+1 and mat[cur][tar]==1:
				num[tar] += num[cur]
				num[tar] %= mo

print num[B]
