import sys

M=[]
for y in range(8):
	M.append(list(raw_input()))

def check(y,x):
	for i in range(8):
		if i!=x and M[y][i]=='Q':
			return 0
		if i!=y and M[i][x]=='Q':
			return 0
	
	for i in range(1,8):
		if y-i>=0 and x-i>=0 and M[y-i][x-i]=='Q':
			return 0
		if y-i>=0 and x+i<8 and M[y-i][x+i]=='Q':
			return 0
		if y+i<8 and x-i>=0 and M[y+i][x-i]=='Q':
			return 0
		if y+i<8 and x+i<8 and M[y+i][x+i]=='Q':
			return 0
	return 1
	

def dfs(left,cy):
	if left == 0:
		for m in M:
			print("".join(m))
		exit()
	for y in range(cy,8):
		for x in range(8):
			if M[y][x]=='Q':
				continue
			if check(y,x)==0:
				continue
			M[y][x]='Q'
			dfs(left-1,y+1)
			M[y][x]='.'


for y in range(8):
	for x in range(8):
		if M[y][x]=='Q' and check(y,x)==0:
			print("No Answer")
			exit()

dfs(5,0)
print("No Answer")


