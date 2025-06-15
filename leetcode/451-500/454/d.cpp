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
vector<pair<int,int>> E[200005];
int P[21][200005],D[200005];
ll DS[202020];

void dfs(int cur,ll ds) {
	DS[cur]=ds;
	FORR(e,E[cur]) if(e.first!=P[0][cur]) D[e.first]=D[cur]+1, P[0][e.first]=cur, dfs(e.first,ds+e.second);
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
    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
		int i,x;
		N=n;
		FOR(i,N) E[i].clear();
		
        FORR(e,edges) {
			E[e[0]].push_back({e[1],e[2]*2});
			E[e[1]].push_back({e[0],e[2]*2});
		}
		dfs(0,0);
		FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
		
		vector<int> ret;
		FORR(q,queries) {
			int u=q[0],v=q[1];
			int lc=lca(u,v);
			ll d=DS[u]+DS[v]-DS[lc]*2;
			if(u==v) {
				ret.push_back(u);
			}
			else if((DS[u]-DS[lc])>=d/2) {
				int cur=u;
				for(i=19;i>=0;i--) if(D[cur]-D[lc]>1<<i) {
					int p=getpar(cur,1<<i);
					if(DS[u]-DS[p]<d/2) cur=p;
				}
				ret.push_back(getpar(cur,1));
			}
			else {
				int cur=v;
				for(i=19;i>=0;i--) if(D[cur]-D[lc]>=1<<i) {
					int p=getpar(cur,1<<i);
					if(DS[v]-DS[p]<=d/2) cur=p;
				}
				ret.push_back(cur);
			}
		}
		return ret;
		
    }
};

