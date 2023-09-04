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


int N;
vector<pair<int,int>> E[2000005];
int P[21][10005],D[10005];
int C[26][10005];

void dfs(int cur) {
	int j;
	FORR(e,E[cur]) if(e.first!=P[0][cur]) {
		D[e.first]=D[cur]+1, P[0][e.first]=cur;
		FOR(j,26) C[j][e.first]=C[j][cur];
		C[e.second][e.first]++;
		dfs(e.first);
	}
}
int getpar(int cur,int up) {
	int i;
	FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
	return cur;
}

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

class Solution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int i,x;
        FOR(i,n) E[i].clear();
        ZERO(C);
        FORR(e,edges) {
			E[e[0]].push_back({e[1],e[2]-1});
			E[e[1]].push_back({e[0],e[2]-1});
		}
		dfs(0);
		FOR(i,19) FOR(x,n) P[i+1][x]=P[i][P[i][x]];
		
		vector<int> R;
		FORR(q,queries) {
			int a=q[0];
			int b=q[1];
			int c=lca(q[0],q[1]);
			int sum=0,ma=0;
			FOR(i,26) {
				int v=C[i][a]+C[i][b]-2*C[i][c];
				sum+=v;
				ma=max(ma,v);
			}
			R.push_back(sum-ma);
			
		}
		return R;
		
    }
};
