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

const int DI=200;
ll dp[DI+2][101010];
const ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
		int i,j;
		int N=nums.size();
		FOR(i,DI+2) {
			FOR(j,N) dp[i][j]=1;
		}
		FOR(j,N) dp[0][j]=nums[j];
		FORR(q,queries) {
			int L=q[0],R=q[1]+1,K=q[2],V=q[3];
			if(K>DI) {
				while(L<R) {
					(dp[0][L]*=V)%=mo;
					L+=K;
				}
			}
			else {
				(dp[K][L]*=V)%=mo;
				R=(R-L+K-1)/K*K+L;
				(dp[K][R]*=modpow(V))%=mo;
			}
		}
		
		for(i=1;i<=DI;i++) {
			FOR(j,N) {
				(dp[0][j]*=dp[i][j])%=mo;
				(dp[i][j+i]*=dp[i][j])%=mo;
			}
		}
		ll ret=0;
		FOR(i,N) ret^=dp[0][i];
		return ret;
		
		
        
    }
};

