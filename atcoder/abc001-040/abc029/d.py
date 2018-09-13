
def num(n):
	d = 0
	while pow(10,d) < n:
		d += 1
	return d*n/10

def dfs(n):
	if n <= 0:
		return 0
	
	c = 1
	while c*10 <= n:
		c *= 10
	
	ret = 0
	for d in range(10):
		if (d+1)*c > n:
			if d == 1:
				ret += (n-c+1)
			return ret + dfs(n - c*d)
		
		ret += num(c)
		if d == 1:
			ret += c

print dfs(input())
