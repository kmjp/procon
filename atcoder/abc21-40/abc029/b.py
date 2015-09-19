
ret = 0
for i in range(12):
	haver = 0
	S=raw_input()
	for c in S:
		if c == 'r':
			haver = 1
	ret += haver

print ret
