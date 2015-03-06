#include <bits/stdc++.h>
using namespace std;

int main(int argc,char** argv){
	int N, M, C;
	
	cin >> N >> M >> C;
	
	// N‚ª¬‚³‚­‚È‚é‚æ‚¤‚Éswap
	if(N > M) swap(N,M);
	
	if(N==1) {
		// N==1‚ÌAM‚ª‚RˆÈã‚¾‚ÆğŒ‚ğ–‚½‚³‚È‚¢
		if(M==2) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	else {
		// N,M>1‚È‚çAc‰¡‚Ç‚¿‚ç‚©‚ª‹ô”‚È‚çğŒ‚ğ–‚½‚·B
		if (N*M % 2 == 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	
	return 0;
}

