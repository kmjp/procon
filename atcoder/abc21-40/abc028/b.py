
cnt={}
S=raw_input().strip()
for c in S:
	cnt[c] = cnt.get(c,0) + 1

print "%d %d %d %d %d %d" % (cnt.get('A',0),cnt.get('B',0),cnt.get('C',0),cnt.get('D',0),cnt.get('E',0),cnt.get('F',0))
	
	
