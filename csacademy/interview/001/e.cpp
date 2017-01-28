#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int query(int index) {
    cout << "Q " << index << "\n";
    cout.flush();
    int value;
    cin >> value;
    return value;
}

int solve(int N) {
	if(N==1) return 0;
	int L=0, R=N-1;
	int LV=query(L+1);
	int RV=query(R+1);
	if(LV<RV) return 0;
	while(R-L>1) {
		int M=(L+R)/2;
		int MV=query(M+1);
		if(LV<MV) {
			L=M;
			LV=MV;
		}
		else {
			R=M;
			RV=MV;
		}
	}
	return R;
	
}

int main() {
    int N;
    cin >> N;
    cout << "A " << solve(N) << "\n";
    cout.flush();
    return 0;
}
