import sys

N=input()

h = N/3600
m = N/60%60
s = N%60

print "%02d:%02d:%02d" % (h,m,s)

