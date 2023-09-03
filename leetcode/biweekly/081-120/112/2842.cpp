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

ll score[27];
ll pat[27];

class Solution {
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
		int C[26]={};
		FORR(c,s) {
			c-='a';
			C[c]++;
		}
		
		if(k>26) return 0;
		
		MINUS(score);
		ZERO(pat);
		score[0]=0;
		pat[0]=1;
		int i,j;
		FOR(i,26) if(C[i]) {
			for(j=25;j>=0;j--) {
				if(score[j]+C[i]>score[j+1]) {
					score[j+1]=score[j]+C[i];
					pat[j+1]=0;
				}
				if(score[j]+C[i]==score[j+1]) {
					(pat[j+1]+=pat[j]*C[i])%=mo;
				}
			}
		}
		
		return pat[k];
    }
};
