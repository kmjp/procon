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


vector<int> E[202020],V[202020];
int S[202020];

class Solution {
public:
	int dfs(int cur,int pre) {
		int i,n=E[cur].size();
		FOR(i,n) if(E[cur][i]!=pre) {
			V[cur][i]=dfs(E[cur][i],cur);
			S[cur]+=V[cur][i];
		}
		return max(S[cur],0);
		
	}
	void dfs2(int cur,int pre,int par) {
		S[cur]+=par;
		int i,n=E[cur].size();
		FOR(i,n) if(E[cur][i]==pre) V[cur][i]=par;
		FOR(i,n) if(E[cur][i]!=pre) {
			dfs2(E[cur][i],cur,max(0,S[cur]-V[cur][i]));
		}
	}
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
		int i;
		FOR(i,n) E[i].clear(),V[i].clear();
		FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
			V[e[0]].push_back(0);
			V[e[1]].push_back(0);
		}
		FOR(i,n) {
			if(good[i]) S[i]=1;
			else S[i]=-1;
		}
		dfs(0,0);
		dfs2(0,0,0);
		vector<int> ret;
		FOR(i,n) {
			int cur=(good[i])?1:-1;
			FORR(e,V[i]) cur+=e;
			ret.push_back(cur);
		}
		return ret;
    }
};


