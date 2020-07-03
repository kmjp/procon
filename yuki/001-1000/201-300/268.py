# -*- coding: utf-8 -*-

# 3辺の長さ
L = map(int,raw_input().strip().split())
# リボンの巻き回数
M = map(int,raw_input().strip().split())

# 赤いリボンは長さ  R*2*(H+D)
# 青いリボンは長さ  B*2*(W+H)
# 黄色リボンは長さ  Y*2*(W+D)

# まずリボンの回数をソート
M.sort()

# 各2辺について、１周分の長さをソート
A = [2*(L[0]+L[1]), 2*(L[1]+L[2]), 2*(L[2]+L[0])]
A.sort()

# 大きいものと小さいものを掛け合わせる
print A[0]*M[2] + A[1]*M[1] + A[2]*M[0]
