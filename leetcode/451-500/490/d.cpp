#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

ll comb(int P_,int Q_) {
	static const int N_=20;
	static ll C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j]);
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}

class Solution {
public:
    int countSequences(vector<int>& nums, long long k) {
        int C[7]={};
        ll p=1;
        FORR(a,nums) {
			C[a]++;
			if(a==1) p*=3;
		}
		map<pair<ll,ll>,ll> F,T;
		F[{1,1}]=p;
		int i,j;
		for(i=2;i<=6;i++) {
			T.clear();
			int num=C[i];
			for(int a=0;a<=num;a++) for(int b=0;a+b<=num;b++) {
				ll p=1;
				FOR(j,abs(a-b)) p*=i;
				ll v=comb(num,a)*comb(num-a,b);
				FORR2(x,y,F) {
					if(a>=b) T[{x.first*p,x.second}]+=y*v;
					else T[{x.first,x.second*p}]+=y*v;
				}
				
			}
			
			
			swap(F,T);
		}
		
		ll ret=0;
		FORR2(a,b,F) if(__int128(a.second)*k==a.first) ret+=b;
		return ret;
        
        
    }
};


