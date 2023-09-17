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

vector<pair<int,int>> E[202020];
vector<int> R;


class Solution {
public:
	void dfs2(int cur,int pre,int sum) {
		R[cur]=sum;
		FORR(e,E[cur]) if(e.first!=pre) {
			dfs2(e.first,cur,sum-e.second);
		}
	}
	int dfs(int cur,int pre) {
		int sum=0;
		FORR(e,E[cur]) if(e.first!=pre) {
			if(e.second==1) sum++;
			sum+=dfs(e.first,cur);
		}
		return sum;
	}
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        int i;
        FOR(i,n) {
			E[i].clear();
		}
		R.resize(n);
		FORR(a,edges) {
			E[a[0]].push_back({a[1],-1});
			E[a[1]].push_back({a[0],1});
		}
		int cur=0;
		cur=dfs(0,0);
		dfs2(0,0,cur);
		return R;
    }
};
