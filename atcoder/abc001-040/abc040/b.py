N=input()
mi = 101010

for w in range(1,N+1):
	h = N/w
	if h > 0:
		mi = min(mi, N-w*h + abs(w-h))

print mi
