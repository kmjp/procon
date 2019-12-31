#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import math
import codecs

sys.stdin  = codecs.getreader('utf-8')(sys.stdin)
sys.stdout = codecs.getwriter('utf-8')(sys.stdout)

N=input()
L={}
LL=[]
S=[]

for i in range(N):
	s = raw_input().strip()
	L[s]=1
	LL.append(s[0])
	LL.append(s[1])

for i in range(5):
	S.append(raw_input())

for s in LL:
	if S[1][2]==u"↑":
		t = s+S[0][2]
	else:
		t = S[0][2]+s
	
	if t not in L:
		continue
		
	if S[3][2]==u"↑":
		t = S[4][2]+s
	else:
		t = s+S[4][2]
	
	if t not in L:
		continue
		
	if S[2][1]==u"←":
		t = s+S[2][0]
	else:
		t = S[2][0]+s
		
	if t not in L:
		continue
		
	if S[2][3]==u"←":
		t = S[2][4]+s
	else:
		t = s+S[2][4]
	if t not in L:
		continue
	print s
	break



