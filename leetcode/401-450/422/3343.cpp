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

const ll mo=1000000007;
ll from[821][82];
ll to[821][82];

ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

class Solution {
public:
    int countBalancedPermutations(string num) {
		int N=num.size();
		int S=0;
		ZERO(from);
		
		int x,y,k,i;
		from[0][0]=1;
		int C[10]={};
		FORR(c,num) C[c-'0']++;
		int O=(N+1)/2,E=N/2;
		int CN=0;
		FOR(i,10) {
			ZERO(to);
			
			for(x=400;x>=0;x--) for(y=40;y>=0;y--) if(from[x][y]) {
				int LO=O-y;
				int LE=E-(CN-y);
				if(LO>=0&&LE>=0) {
					for(k=0;k<=C[i];k++) if(LO>=k&&LE>=C[i]-k) {
						(to[x+k*i][y+k]+=from[x][y]*comb(LO,k)%mo*comb(LE,C[i]-k))%=mo;
					}
				}
			}
			CN+=C[i];
			S+=i*C[i];
			swap(from,to);
			
		}
		
		if(S%2) return 0;
		return from[S/2][O];
		
        
    }
};
