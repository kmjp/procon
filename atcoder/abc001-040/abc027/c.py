N=input()
step = 0
while 1<<(step+1) <= N:
	step += 1

res = 0
if step % 2 == 0:
	res = 0
	for i in range(step):
		if i%2==0 and (N&(1<<(step-1-i)))==0:
			res = 1
			break
		elif i%2==1 and (N&(1<<(step-1-i)))>0:
			res = 0
			break
else:
	res = 1
	for i in range(step):
		if i%2==0 and (N&(1<<(step-1-i)))>0:
			res = 1
			break
		elif i%2==1 and (N&(1<<(step-1-i)))==0:
			res = 0
			break

ans=["Takahashi","Aoki"]
print ans[1-res]

