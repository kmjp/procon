
mo = 1000000007

def rev(v):
	return pow(v,mo-2,mo)

A = input()
B = input()
C = input()

AoB = A * rev(B) % mo
AoC = A * rev(C) % mo

RC1 = rev(AoB + AoC - 1)
R1 = AoC * RC1 % mo
C1 = AoB * RC1 % mo

print "%d %d" % (R1-1,C1-1)
