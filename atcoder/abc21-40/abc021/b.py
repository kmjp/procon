import sys

N = input()
A,B = map(int,raw_input().strip().split(" "))

K = input()
P = map(int,raw_input().strip().split(" "))

num = [0]*105
num[A] += 1
num[B] += 1

for i in P:
	num[i]+=1

for i in range(0,105):
	if num[i] > 1:
		print "NO"
		sys.exit()

print "YES"
