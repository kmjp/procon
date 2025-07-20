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

ll N;
int depth[101];
ll dp[61][2][61];

ll dfs(int d,int le,int num) {
	if(num<0) return 0;
	if(num==0&&le) return 1;
	if(d<0) return 0;
	if(dp[d][le][num]>=0) return dp[d][le][num];
	ll ret=0;
	
	int a;
	FOR(a,2) {
		if((N>>d)%2==0&&le==0&&a==1) continue;
		ret+=dfs(d-1,le|(a<(N>>d)%2),num-a);
	}
	return dp[d][le][num]=ret;
}


class Solution {
public:
    long long popcountDepth(long long n, int k) {
		if(k==0) return 1;
        vector<int> cand[10];
        int i;
		N=n;
		MINUS(dp);
		
		ll ret=0;
        for(i=1;i<=55;i++) {
			if(i>1) depth[i]=1+depth[__builtin_popcount(i)];
			if(depth[i]==k-1) {
				ret+=dfs(60,0,i);
				if(__builtin_popcountll(n)==i) ret++;
			}
		}
		if(k==1) ret--;
		return ret;
    }
};

