import sys
import math
import re

mi=-1<<60
S=raw_input().strip()

for i in range(11):
	S=S[1:]+S[0]
	if S[0]=='+':
		continue
	if S[0]=='-':
		continue
	if S[-1]=='+':
		continue
	if S[-1]=='-':
		continue
	s = re.sub(r'(\d+)', lambda m:str(int(m.group())), S)
	mi=max(mi,eval(s))

print mi
