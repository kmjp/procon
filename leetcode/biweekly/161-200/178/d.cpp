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


string S;
ll dp[16][136][2][4][10][2];

class Solution {
public:
	int goodsum(int sum) {
		string v=to_string(sum);
		int i,j;
		FOR(j,2) {
			reverse(ALL(v));
			FOR(i,v.size()-1) if(v[i]<=v[i+1]) break;
			if(i==v.size()-1) return 1;
		}
		return 0;
	}

	ll dfs(int d,int sum,int le,int mask,int p,int l0) {
		if(d>=S.size()) {
			if(goodsum(sum)||mask!=3) return 1;
			return 0;
		}
		if(dp[d][sum][le][mask][p][l0]!=-1) return dp[d][sum][le][mask][p][l0];
		ll ret=0;
		
		for(int v=0;v<=9;v++) {
			if(!le&&v>S[d]-'0') continue;
			int nle=le|(v<S[d]-'0');
			int nl0=l0&&(v==0);
			int nmask=mask;
			if(l0) {
				nmask=0;
			}
			else {
				if(v<=p) nmask|=1;
				if(v>=p) nmask|=2;
				
			}
			ret+=dfs(d+1,sum+v,nle,nmask,v,nl0);
		}
		
		return dp[d][sum][le][mask][p][l0]=ret;
		
		
	}
	
	ll hoge(ll v) {
		S=to_string(v);
		MINUS(dp);
		return dfs(0,0,0,0,0,1);
	}
    long long countFancy(long long l, long long r) {
        return hoge(r)-hoge(l-1);
    }
};


