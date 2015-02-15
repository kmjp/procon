import sys
import re

x,y,W=raw_input().split(" ")
x=int(x)-1
y=int(y)-1
S=[]
for i in range(0,9):
	S.append(raw_input())

ma={"R":(1,0),"L":(-1,0),"U":(0,-1),"D":(0,1),"RU":(1,-1),"RD":(1,1),"LU":(-1,-1),"LD":(-1,1)}
tx=ma[W][0]
ty=ma[W][1]


res = ''
for i in range(0,4):
	res += S[y][x]
	y += ty
	x += tx
	if x < 0:
		x = 1
		tx = -tx
	if x > 8:
		x = 7
		tx = -tx
	if y < 0:
		y = 1
		ty = -ty
	if y > 8:
		y = 7
		ty = -ty

print(res)
