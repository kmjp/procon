import sys

N = input()
H = [0]*N
R = [0]*N
stack = []

for i in range(0,N):
	H[i]=input()

for i in range(0,N):
	while len(stack) > 0 and H[stack[-1]] < H[i]:
		R[stack[-1]] += i-stack[-1]-1
		stack.pop()
	stack.append(i)

for i in stack:
	R[i] += N-i-1

stack = []
for i in range(0,N)[::-1]:
	while len(stack) > 0 and H[stack[-1]] < H[i]:
		R[stack[-1]] += stack[-1]-i-1
		stack.pop()
	stack.append(i)

for i in stack:
	R[i] += i

for i in range(0,N):
	print R[i]

