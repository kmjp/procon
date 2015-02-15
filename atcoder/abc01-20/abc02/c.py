import sys

a=map(int,raw_input().strip().split(" "))

s=a[0]*(a[3]-a[5])+a[2]*(a[5]-a[1])+a[4]*(a[1]-a[3])
print "%f" % (abs(s)/2.0)

