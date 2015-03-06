# -*- coding: utf-8 -*-

# 入力
N,L = map(int,raw_input().strip().split())
X = [0]*(N+1)
W = [0]*(N+1)
T = [0]*(N+1)

for i in range(N):
	X[i],W[i],T[i] = map(int,raw_input().strip().split())


# 友人宅=最後の交差点と考えた方が楽です
X[N] = L

# 次の交差点まで進む時間を計算
current = X[0]

for i in range(N):
	# 信号は2*T[i]周期で青赤切り替わる。
	# 青信号の間に交差点を渡るには、W[i]後まで青信号ならいいので、
	# (今の時刻) % (2*T[i])が(T[i]-W[i])以下なら渡りきれる。
	# 逆に(T[i]-W[i])を超えるなら次の青信号を待つ
	if current % (2*T[i]) > T[i]-W[i]:
		current += 2*T[i] - (current % (2*T[i]))
	
	# 次の交差点まで進む
	current += X[i+1]-X[i]

print current

