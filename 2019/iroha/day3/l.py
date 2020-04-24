import fractions

lcm = 1
for i in range(1,1001):
	lcm = lcm//fractions.gcd(i,lcm)*i

for i in range(1,1001):
	print(lcm-i)


