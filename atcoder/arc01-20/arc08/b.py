import sys

N,M=map(int,raw_input().split(" "))
name=list(raw_input())
kit=(raw_input())

a={}
b={}
for n in name:
	a[n] = a.get(n,0)+1
for k in kit:
	b[k] = b.get(k,0)+1

r = 0
for key in a:
	if b.get(key,0) == 0:
		r = -1
		break
	r = max(r, (a[key]+(b[key]-1))/b[key])

print(r)




