import sys

A=raw_input().strip()
B=input()
print A[(B-1)%len(A)]

