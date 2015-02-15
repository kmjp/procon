import sys
import math

N,K=map(int,raw_input().strip().split(" "))
R = N*K/10
N,K=map(int,raw_input().strip().split(" "))
R += N*K/10
N,K=map(int,raw_input().strip().split(" "))
R += N*K/10

print R
