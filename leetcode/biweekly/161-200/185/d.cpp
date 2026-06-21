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


ll dp[20][2][2][10];
ll p10[18];
ll V,K;

ll dfs(int d,int le,int first,int pre) {
	if(d<0) return 1;
	if(dp[d][le][first][pre]>=0) return dp[d][le][first][pre];
	ll ret=0;
	
	int cd=V/p10[d]%10;
	int i;
	FOR(i,10) {
		if(!first&&abs(pre-i)>K) continue;
		if(le==0&&i>cd) continue;
		ret+=dfs(d-1,le|i<cd,first&(i==0),i);
	}
	
	
	return dp[d][le][first][pre]=ret;
}

class Solution {
public:
    long long goodIntegers(long long l, long long r, int k) {
		int i;
		p10[0]=1;
		FOR(i,17) p10[i+1]=p10[i]*10;
		
		MINUS(dp);
		K=k;
		V=r;
		ll ret=dfs(17,0,1,0);
		MINUS(dp);
		V=l-1;
		ret-=dfs(17,0,1,0);
		return ret;
        
    }
};

