import sys

S=raw_input()
T=raw_input()

ng=0
for i in range(0,len(S)):
	ss=S[i]
	tt=T[i]
	if S[i]=="@" or T[i]=="@":
		if "atcoder".find(S[i]) != -1:
			ss="@"
		if "atcoder".find(T[i]) != -1:
			tt="@"
	if ss!=tt:
		ng = 1

if ng == 0:
	print "You can win"
else:
	print "You will lose"

