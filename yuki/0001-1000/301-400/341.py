#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import math
import codecs

sys.stdin  = codecs.getreader('utf-8')(sys.stdin)
sys.stdout = codecs.getwriter('utf-8')(sys.stdout)

S=raw_input().strip()
ma = 0
len = 0
for c in S:
	if c==u"…":
		len = len+1
	else:
		len = 0
	ma=max(ma,len)
print ma


