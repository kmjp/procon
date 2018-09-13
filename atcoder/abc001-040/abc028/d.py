
N,K=map(int,raw_input().strip().split(" "))

total = N**3
yes = 1 + 3*(N-K) + 3*(K-1) + 6*(N-K)*(K-1)

print "%.12f" % (yes*1.0/total)
