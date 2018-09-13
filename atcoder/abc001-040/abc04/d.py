import sys

R,G,B=map(int,raw_input().strip().split(" "))

def calc(x,num):
	if x <= -num:
		return (-x-x-num+1)*num/2
	if x >= 0:
		return (x+x+num-1)*num/2
		
	y=x+num-1
	x=-x
	return (x+1)*x/2+(y+1)*y/2

mi=100000000

for g in range(-400,400):
	r = min(g-R,-100-R/2)
	b = max(g+G,100-B/2)
	mi = min(mi,calc(r+100,R)+calc(g,G)+calc(b-100,B))

print mi



