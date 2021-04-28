#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++) {
    cin >> A.at(i) >> B.at(i);
  }
  int x,y;

  // ここにプログラムを追記
  // (ここで"試合結果の表"の2次元配列を宣言)
  int X[101][101]={};
  for (int i = 0; i < M; i++) {
	X[A[i]-1][B[i]-1]=1;
	X[B[i]-1][A[i]-1]=2;
  }
  for(y=0;y<N;y++) {
	for(x=0;x<N;x++) {
		if(X[y][x]==0) cout<<"-";
		if(X[y][x]==1) cout<<"o";
		if(X[y][x]==2) cout<<"x";
		if(x==N-1) cout<<endl;
		else cout<<" ";
	}
}
}

