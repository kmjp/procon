import sys
import math

S=raw_input().strip()

while len(S) > 0:
	if S.startswith("ch"):
		S=S[2:]
	elif S.startswith("o") or S.startswith("k") or S.startswith("u"):
		S=S[1:]
	else:
		print "NO"
		sys.exit(0)

print "YES"
