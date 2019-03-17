
N=int(input())
M=int(input())

if N%2:
	M-=10
	
if M%2 or M<0:
	print("No")
else:
	print("Yes")
