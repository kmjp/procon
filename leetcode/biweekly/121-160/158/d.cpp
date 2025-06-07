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


int dp[505][1<<10];
const ll mo=1000000007;
vector<int> C[505];
int V[505];
int N;
ll ret=0;

class Solution {
public:
	void dfs(int cur) {
		int mask;
		FORR(e,C[cur]) {
			dfs(e);
			FOR(mask,1<<10) dp[cur][mask]=max(dp[cur][mask],dp[e][mask]);
		}
		mask=0;
		int v=V[cur];
		while(v) {
			int a=v%10;
			if(mask&(1<<a)) break;
			mask |= 1<<a;
			v/=10;
		}
		if(v==0) {
			dp[cur][mask]=max(dp[cur][mask],V[cur]);
		}
		ll d[1<<10]={};
		ll c=0;
		FOR(mask,1<<10) {
			for(int sm=mask;sm>=0;sm--) {
				sm&=mask;
				d[mask]=max(d[mask],d[sm]+dp[cur][mask^sm]);
			}
			c=max(c,d[mask]);
		}
		ret=(ret+c)%mo;
		
		
		
	}

    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
		N=vals.size();
		ZERO(dp);
		int i;
		FOR(i,N) {
			V[i]=vals[i];
			C[i].clear();
		}
		FOR(i,N) if(par[i]!=-1) C[par[i]].push_back(i);
		ret=0;
		dfs(0);
		return ret%mo;
		
		
		
		
        
    }
};


