import sys

B=map(int,raw_input().split(" "))
L=map(int,raw_input().split(" "))

m=max((B[0]/L[0])*(B[1]/L[1])*(B[2]/L[2]),(B[1]/L[0])*(B[0]/L[1])*(B[2]/L[2]))
m=max(m, (B[0]/L[0])*(B[2]/L[1])*(B[1]/L[2]), (B[1]/L[0])*(B[2]/L[1])*(B[0]/L[2]))
m=max(m, (B[2]/L[0])*(B[0]/L[1])*(B[1]/L[2]), (B[2]/L[0])*(B[1]/L[1])*(B[0]/L[2]))

print(m)



