#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;

  // �����Ƀv���O������ǋL
  int i;
  for(i=1;i<=N;i++) {
	string s;
	int B;
	cin>>s>>B;
	if(s=="+") {
		A+=B;
	}
	if(s=="-") {
		A-=B;
	}
	if(s=="*") {
		A*=B;
	}
	if(s=="/") {
		if(B==0) {
			cout<<"error"<<endl;
			break;
		}
		A/=B;
	}
	cout<<i<<":"<<A<<endl;
}
}
