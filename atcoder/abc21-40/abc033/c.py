S=raw_input()

ret = 0
zero = 0
for c in S:
	if c=='0':
		zero=1
	elif c=='+':
		ret += 1-zero
		zero=0

print ret + (1-zero)

