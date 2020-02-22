import sys
import re
 
N=input()
A=re.split("[ \.]",raw_input())
tot=0
for a in A:
	if a == "TAKAHASHIKUN":
		tot += 1
	if a == "Takahashikun":
		tot += 1
	if a == "takahashikun":
		tot += 1
 
print(tot)
