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


vector<int> E1[101010];
vector<int> E2[101010];
int D[101010];
int C[2];
int X[2];

class Solution {
public:
	void dfs1(int cur,int pre,int k) {
		D[cur]=k;
		C[k]++;
		FORR(e,E1[cur]) if(e!=pre) dfs1(e,cur,k^1);
	}
	void dfs2(int cur,int pre,int k) {
		X[k]++;
		FORR(e,E2[cur]) if(e!=pre) dfs2(e,cur,k^1);
	}
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
		int N=edges1.size()+1;
		int M=edges2.size()+1;
		int i;
		FOR(i,N) E1[i].clear();
		FOR(i,M) E2[i].clear();
		FORR(e,edges1) E1[e[0]].push_back(e[1]),E1[e[1]].push_back(e[0]);
		FORR(e,edges2) E2[e[0]].push_back(e[1]),E2[e[1]].push_back(e[0]);
		ZERO(D);
		ZERO(C);
		ZERO(X);
		dfs1(0,0,0);
		dfs2(0,0,0);
		vector<int> R;
		FOR(i,N) R.push_back(C[D[i]]+max(X[0],X[1]));
		return R;
		
        
    }
};

