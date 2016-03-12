W,H=map(int,raw_input().strip().split(" "))

a=1
b=1
mo = 1000000007

for i in range(1,W):
	a = a * i % mo
	b = b * i % mo

for i in range(1,H):
	a = a * (W-1+i) % mo
	b = b * i % mo

print a * pow(b, mo-2, mo) % mo

