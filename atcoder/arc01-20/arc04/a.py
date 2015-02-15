import sys

N=input()

for i in range(0,N):
	XY=raw_input().split(" ")
	S.append((int(XY[0]),int(XY[1])))

ma=0.0
for i in range(0,N):
	for j in range(0,N):
		ma=max(ma, ((S[i][0]-S[j][0])**2+(S[i][1]-S[j][1])**2)**0.5)

print(ma)


