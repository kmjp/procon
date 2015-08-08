N=input()
A=map(int,raw_input().strip().split(" "))

sum = 0
for a in A:
	sum += a

if sum % N > 0:
	print -1
else:
	ave = sum/N
	tot = num = res = 0
	for a in A:
		tot += a
		num += 1
		if tot != ave*num:
			res += 1
	print res
