import sys

def iskigo(c):
	if c.isdigit() or c.isalpha():
		return 0
	return 1

def hoge(tail,S):
	id = S.rfind(tail)
	if id < 0:
		return 0
	id += len(tail)
	if len(S) - id > 3:
		return 0
	
	for i in range(id,len(S)):
		if iskigo(S[i])==0:
			return 0
	return 1

while 1:
	try:
		S=raw_input()
	except:
		break
	
	yes = 0
	if S.startswith("digi "):
		yes = hoge("nyo",S[5:].lower())
	elif S.startswith("petit "):
		yes = hoge("nyu",S[6:].lower())
	elif S.startswith("rabi "):
		for i in S[5:]:
			if iskigo(i)==0:
				yes=1
	elif S.startswith("gema "):
		yes = hoge("gema",S[5:].lower())
	elif S.startswith("piyo "):
		yes = hoge("pyo",S[5:].lower())
	
	if yes == 1:
		print "CORRECT (maybe)"
	else:
		print "WRONG!"
