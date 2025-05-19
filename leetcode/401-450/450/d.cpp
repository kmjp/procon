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
ll SD[200005];
int L[202020],R[202020],re[202020];
int id;

void dfs(int cur) {
	L[cur]=id++;
	re[L[cur]]=cur;
	FORR(e,E[cur]) if(e.first!=P[0][cur]) D[e.first]=D[cur]+1,SD[e.first]=SD[cur]+e.second,P[0][e.first]=cur, dfs(e.first);
	R[cur]=id;
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
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        N=edges.size()+1;
        int i,x;
        FOR(i,N) E[i].clear();
        FORR(e,edges) {
			E[e[0]].push_back({e[1],e[2]});
			E[e[1]].push_back({e[0],e[2]});
		}
		id=0;
		dfs(0);
		FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
		
		vector<int> ret;
		FORR(q,queries) {
			sort(ALL(q));
			int v=1<<30;
			do {
				int a=q[0],b=q[1],c=q[2];
				int ab=lca(a,b);
				int abc=lca(ab,c);
				int cand=SD[a]+SD[b]-2*SD[ab]+SD[ab]+SD[c]-2*SD[abc];
				v=min(v,cand);
			} while(next_permutation(ALL(q)));
			
			
			
			ret.push_back(v);
			
			
			
			
		}
		return ret;

    }
};


