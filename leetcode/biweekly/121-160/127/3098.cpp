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

map<pair<int,int>,ll> dp[55];

class Solution {
public:
    int sumOfPowers(vector<int>& nums, int k) {
		int N=nums.size();
		sort(ALL(nums));
		int i;
		FOR(i,N+1) dp[i].clear();
		dp[0][{1<<30,0}]=1;
		
		ll ret=0;
		FORR(n,nums) {
			for(i=k-1;i>=0;i--) FORR(a,dp[i]) {
				int dif=a.first.first;
				int la=a.first.second;
				ll v=a.second%mo;
				if(i==0) {
					dp[i+1][{dif,n}]+=v;
				}
				else if(i==k-1) {
					(ret+=1LL*min(dif,n-la)*v)%=mo;
				}
				else {
					dp[i+1][{min(dif,n-la),n}]+=v;
				}
			}
		}
		
		return ret;
		
        
    }
};

