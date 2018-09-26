class GroupTheNumbers():
	def calculate(self,a):
		n0 = nm = 0
		p = []
		m = []
		
		ret = 0
		for v in a:
			if v==0:
				n0 += 1
			elif v == 1:
				ret += 1
			elif v>0:
				p.append(v)
			else:
				m.append(v)
		if nm:
			m.append(-1)
		
		m.sort()
		if len(m)%2==1:
			if n0==0:
				ret += m[-1]
			m = m[:-1]
		while len(m) and m[-1]==-1 and m[-2]==-1:
			ret += 1
			m.pop()
			m.pop()
			

		if len(p)+len(m):
			b = 1
			for v in p:
				b *= v
			for v in m:
				b *= v
			ret += b
		rets = str(ret)
		if len(rets)>203:
			rets = rets[0:100] + "..." + rets[-100:]
		
		return rets

a=GroupTheNumbers()
print(a.calculate((305802003, 136316694, 621448948, -175990184, 52551547, -566608000, 141205973, -137352529, 226239209, 73136038,
 345723809, 420451378, 455689639, -228162827, 593253055, 280556479, -470339174, -606141985, 594940027, -71768243,
 -475458047, 145718435, 441912314, -622312734, -701346268, 514619489, -280198616, -499528618, 545548925, 
 -219590088, 607143343, 481228395, -208750264, 212639054, 59098345, 177587003, 456261200)))
