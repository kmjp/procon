import sys

N=input()
bm=[0 for j in range(24*12+1)]
for i in range(N):
	x,y=map(int,raw_input().strip().split("-"))
	x=x/100*60+x%100
	y=y/100*60+y%100
	if x%5 > 0:
		x-=x%5
	if y%5 > 0:
		y+=5-y%5
	for z in range(x,y,5):
		bm[z/5]=1

i=0
while i<=24*12:
	if bm[i]==0:
		i+=1
		continue
	
	s=i
	while i<=24*15 and bm[i]==1:
		i+=1
	print "%02d%02d-%02d%02d" % (s/12,s%12*5,i/12,i%12*5)
