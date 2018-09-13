
H,M=map(int,raw_input().strip().split(" "))
H %= 12

short = M*6
long = (H*60+M)/2.0
dif = abs(short-long)

print min(dif,360-dif)
