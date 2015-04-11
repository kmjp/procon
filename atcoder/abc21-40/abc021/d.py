
mo = 1000000007

def comb(n,k):
	if k < 0 or k > n:
		return 0
	fact  = [0]*(n+1)
	factr = [0]*(n+1)
	inv   = [0]*(n+1)
	fact[0]=factr[0]=inv[1]=1
	for i in range(2,n+1):
		inv[i] = inv[mo % i] * (mo - mo/i) % mo
	for i in range(1,n+1):
		fact[i] = fact[i-1] * i % mo
		factr[i] = factr[i-1] * inv[i] % mo
	return fact[n] * factr[k] * factr[n-k] % mo

def hcomb(n,k):
	if n==0 and k==0:
		return 1
	return comb(n+k-1,k)

N=input()
K=input()
print hcomb(N,K)
