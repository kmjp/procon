N,K=map(int,raw_input().strip().split(" "))
A=map(int,raw_input().strip().split(" "))
S=[0] * (N+1)
for i in range(N):
	S[i+1] = S[i] + A[i]

ret = 0
for i in range(K-1,N):
	ret += S[i+1]-S[i+1-K]

print ret
