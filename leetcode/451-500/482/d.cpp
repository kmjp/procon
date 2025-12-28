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

ll dp[2][20][200];
ll p10[17];
class Solution {
public:
	ll V;
	ll dfs(int d,int dif,int le) {
		if(d==-1) return dif==100;
		if(dif<10||dif>=190) return 0;
		if(dp[le][d][dif]!=-1) return dp[le][d][dif];
		int rdif=100+(100-dif);
		
		int i;
		int td=V/p10[d]%10;
		ll ret=0;
		FOR(i,10) {
			if(le==0&&i>td) continue;
			ret+=dfs(d-1,rdif+i,le||i<td);
		}
		return dp[le][d][dif]=ret;
		
	}

	ll hoge(ll v) {
		V=v;
		MINUS(dp);
		
		return dfs(16,100,0);
		
	}
    long long countBalanced(long long low, long long high) {
		int i;
		p10[0]=1;
		FOR(i,16) {
			p10[i+1]=p10[i]*10;
		}
		return hoge(high)-hoge(low-1);
        
    }
};

