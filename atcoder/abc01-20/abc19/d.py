import sys

N=input()
ma = id = 0
for i in range(1,N):
	print "? {0} {1}".format(1, i+1)
	sys.stdout.flush()
	dist = int(raw_input())
	if dist > ma:
		id = i
		ma = dist

ma = 0
for i in range(0,N):
	print "? {0} {1}".format(id+1, i+1)
	sys.stdout.flush()
	dist = int(raw_input())
	if dist > ma:
		ma = dist

print "! %d" % (ma)

