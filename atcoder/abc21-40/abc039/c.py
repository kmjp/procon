T=raw_input().strip()

S="WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW"
A=["Do","Re","Mi","Fa","So","La","Si"]
B=[0,2,4,5,7,9,11]

for i in range(7):
	if T == S[B[i]:B[i]+20]:
		print A[i]

