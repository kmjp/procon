#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import math
import codecs

sys.stdin  = codecs.getreader('utf-8')(sys.stdin)
sys.stdout = codecs.getwriter('utf-8')(sys.stdout)


S=raw_input().strip()
while S.startswith(u"ｗ"):
	S = S[1:]

L=[]
for c in S:
	if len(L)==0 or ((c==u"ｗ") ^ (L[-1].find(u"ｗ")!=-1)):
		L.append(c)
	else:
		L[-1] += c

ma=0
for c in L:
	if c.find(u"ｗ")!=-1:
		ma = max(ma,len(c))

for i in range(len(L)):
	c = L[i]
	if c.find(u"ｗ")!=-1 and len(c) == ma:
		print L[i-1]
