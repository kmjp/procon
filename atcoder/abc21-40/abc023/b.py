import sys

L=input()
S=raw_input().strip()

A=["b"]

while len(A[-1])<=100:
	A.append("a"+A[-1]+"c")
	A.append("c"+A[-1]+"a")
	A.append("b"+A[-1]+"b")

for i in range(len(A)):
	if A[i] == S:
		print i
		sys.exit(0)

print -1
