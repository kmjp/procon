import sys

D,S=map(int,raw_input().strip().split(" "))
w=0

tab=["N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW","N"]
wd=[0.0,0.3,1.6,3.4,5.5,8.0,10.8,13.9,17.2,20.8,24.5,28.5,32.7]
S=int((S/60.0+0.05)*10+0.0001)/10.0
w=0
for r in range(0,len(wd)):
	if S>=wd[r]:
		w=r

if w==0:
	print "C 0"
else:
	print "%s %d" % (tab[int((D/10.0+11.25)/22.50)],w)
