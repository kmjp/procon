#include <bits/stdc++.h>
using namespace std;

int main(int argc,char** argv){
	int N, M, C;
	
	cin >> N >> M >> C;
	
	// N���������Ȃ�悤��swap
	if(N > M) swap(N,M);
	
	if(N==1) {
		// N==1�̎��AM���R�ȏゾ�Ə����𖞂����Ȃ�
		if(M==2) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	else {
		// N,M>1�Ȃ�A�c���ǂ��炩�������Ȃ�����𖞂����B
		if (N*M % 2 == 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	
	return 0;
}

