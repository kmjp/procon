import sys

B=[];
for i in range(19):
	B.append(list(raw_input().strip()))

def check(BO):
	for y in range(19):
		for x in range(19):
			if BO[y][x]!='.':
				if x<=14 and BO[y][x]==BO[y][x+1]==BO[y][x+2]==BO[y][x+3]==BO[y][x+4]:
					return 0
				if y<=14 and BO[y][x]==BO[y+1][x]==BO[y+2][x]==BO[y+3][x]==BO[y+4][x]:
					return 0
				if x<=14 and y<=14 and BO[y][x]==BO[y+1][x+1]==BO[y+2][x+2]==BO[y+3][x+3]==BO[y+4][x+4]:
					return 0
				if x>=4 and y<=14 and BO[y][x]==BO[y+1][x-1]==BO[y+2][x-2]==BO[y+3][x-3]==BO[y+4][x-4]:
					return 0
	return 1

no=nx=0
for B2 in B:
	for b in B2:
		if b == 'o':
			no += 1
		if b == 'x':
			nx += 1

t=''
if no==nx:
	t='x'
elif no==nx+1:
	t='o'
else:
	print("NO")
	exit()
	
if nx<5:
	print("YES")
	exit()

for y in range(19):
	for x in range(19):
		if B[y][x]==t:
			B[y][x]="."
			if check(B):
				print("YES")
				exit()
			B[y][x]=t

print("NO")

