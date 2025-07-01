import sys
import math

T=int(input())
for t in range(T):
	A,B,C=map(int,input().strip().split(" "))
	
	p = 0
	q = 1
	num = 0
	cur = 1
	for i in range(1,136):
		cur *= A
		
		while cur % C == 0:
			num += 1
			cur //= C
		# if p/q < num / i
		if p * i < num * q:
			p = num
			q = i
		
	
	print(p * B // q % 998244353)


