#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, S;
  cin >> N >> S;
  vector<int> A(N), P(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int i = 0; i < N; i++) {
    cin >> P.at(i);
  }
  int ret=0,x,y;
  for (int i = 0; i < N; i++) {
	for (int j = 0; j < N; j++) {
		if(A[i]+P[j]==S) ret++;
	}
}
cout<<ret<<endl;
  

  // �����S�E�p�C�i�b�v�������ꂼ��1���w������Ƃ����vS�~�ɂȂ�悤�Ȕ����������ʂ肠�邩
  // �����Ƀv���O������ǋL
}

