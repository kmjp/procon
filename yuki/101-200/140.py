# -*- coding: utf-8 -*-

N = input()
mod = 1000000007

C = [[0 for i in range(N+2)] for j in range(N+2)]
F = [[0 for i in range(N+2)] for j in range(N+2)]
P = [[0 for i in range(N+2)] for j in range(N+2)]

# パスカルの三角形からCombinationの値を作成
for x in range(N+1):
	C[x][0] = 1
	for y in range(1,x+1):
		C[x][y] = (C[x-1][y] + C[x-1][y-1]) % mod

# F[x][y] は 夫婦同じグループに入る夫婦がx組で、そのx組がyグループに分かれる組み合わせ
for x in range(1,N+1):
	F[x][1] = 1
	for y in range(2,x+1):
		# x組がyグループになるのは以下の和
		#   (x-1)組の夫婦が(y-1)グループを作り、x組目の夫婦が新たなグループを作る場合
		#   (x-1)組の夫婦が  y  グループを作り、x組目の夫婦がそのいずれかに含まれる場合
		F[x][y] = (F[x-1][y-1] + y * F[x-1][y]) % mod

# 夫婦同じグループに入る夫婦が既にyグループ作っているとき、同じグループに
# 入らない夫婦が1組いると、その夫婦の分かれ方はy*(y-1)通り。
# z組ならそのz乗。そのようなP[y][z] = (y*(y-1))^z を計算。
for y in range(N+1):
	P[y][0] = 1
	for z in range(N+1):
		P[y][z+1] = P[y][z] * y * (y-1) % mod

ret = 0
for x in range(1,N+1):
	for y in range(1,x+1):
		# N組中x組の夫婦は夫婦で同じグループに入っており、全体でyグループを構成するケース
		# C[N][x] : まずN組の夫婦のうち、夫婦同じグループに入るx組を選ぶ
		# F[x][y] : そのようなx組の夫婦がyグループを構成する組み合わせ
		# P[y][N-x] : 夫婦別のグループに入る(N-x)組のyグループへの分かれ方
		ret = (ret + C[N][x] * F[x][y] * P[y][N-x]) % mod

print ret

