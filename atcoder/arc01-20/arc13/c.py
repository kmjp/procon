import sys

nim=0
N=input()
for i in range(N):
	bx,by,bz=map(int,raw_input().split(" "))
	ix=iy=iz=10**10
	ax=ay=az=0
	M=input()
	for j in range(M):
		hx,hy,hz=map(int,raw_input().split(" "))
		ix=min(ix,hx)
		iy=min(iy,hy)
		iz=min(iz,hz)
		ax=max(ax,hx)
		ay=max(ay,hy)
		az=max(az,hz)
	nim ^= ix^iy^iz^(bx-1-ax)^(by-1-ay)^(bz-1-az)

print("LOSE" if nim==0 else "WIN")
