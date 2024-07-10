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


map<ll,int> M[505050];
set<int> C;

using VT = string;

struct RollingHash {
	static const ll mo0=1000000021,mo1=1000000009;
	static ll mul0,mul1;
	static const ll add0=1000010007, add1=1003333331;
	static vector<ll> pmo[2];
	VT s; int l; vector<ll> hash_[2];
	void init(VT s) {
		this->s=s; l=s.size(); int i,j;
		hash_[0]=hash_[1]=vector<ll>(1,0);
		if(!mul0) mul0=10009+(((ll)&mul0+time(NULL))>>5)%1259,mul1=10007+(time(NULL)+((ll)&mul1)>>5)%2257;
		if(pmo[0].empty()) pmo[0].push_back(1),pmo[1].push_back(1);
		FOR(i,l) hash_[0].push_back((hash_[0].back()*mul0+add0+s[i])%mo0);
		FOR(i,l) hash_[1].push_back((hash_[1].back()*mul1+add1+s[i])%mo1);
	}
	/*ˆÈ‰ºll”Å*/
	ll hash(int l,int r) { // s[l..r]
		if(l>r) return 0;
		while(pmo[0].size()<r+2)
			pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return (((hash_[0][r+1]+(mo0-hash_[0][l]*pmo[0][r+1-l]%mo0))%mo0)<<32) | 
			             ((hash_[1][r+1]+(mo1-hash_[1][l]*pmo[1][r+1-l]%mo1))%mo1);
	}
	ll hash(VT s) { init(s); return hash(0,s.size()-1); }
};
vector<ll> RollingHash::pmo[2]; ll RollingHash::mul0,RollingHash::mul1;
RollingHash rh;

ll dp[505050];

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
		int N=target.size();
		int i;
		C.clear();
		FOR(i,N+2) {
			M[i].clear();
			dp[i]=1LL<<60;
		}
		dp[0]=0;
		FOR(i,words.size()) {
			int L=words[i].size();
			ll h=rh.hash(words[i]);
			C.insert(L);
			if(M[L].count(h)) M[L][h]=min(M[L][h],costs[i]);
			else M[L][h]=costs[i];
		}
		rh.init(target);
		FOR(i,N) if(dp[i]<1LL<<60) {
			FORR(c,C) if(i+c<=N) {
				ll h=rh.hash(i,i+c-1);
				if(M[c].count(h)) {
					dp[i+c]=min(dp[i+c],dp[i]+M[c][h]);
				}
				
			}
		}
		if(dp[N]>=1LL<<60) dp[N]=-1;
		return dp[N];
        
    }
};

