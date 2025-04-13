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
int D[202020];
int DS[202020];
int PDS[202020];
int id;
int L[202020],R[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

class Solution {
public:
	void dfs(int cur,int pre,int d,int ds) {
		D[cur]=d;
		DS[cur]=ds;
		L[cur]=id++;
		bt.add(L[cur],ds);
		bt.add(L[cur]+1,-ds);
		FORR(e,E[cur]) if(e.first!=pre) {
			dfs(e.first,cur,d+1,ds+e.second);
			PDS[e.first]=e.second;
		}
		R[cur]=id;
		
	}
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
		int i;
		FOR(i,n) {
			E[i].clear();
			bt.add(i,-bt(i));
		}
        FORR(e,edges) {
			E[e[0]-1].push_back({e[1]-1,e[2]});
			E[e[1]-1].push_back({e[0]-1,e[2]});
		}
		id=0;
		dfs(0,0,0,0);
		vector<int> ret;
		FORR(q,queries) {
			if(q[0]==1) {
				int x=q[1]-1,y=q[2]-1;
				if(D[x]<D[y]) swap(x,y);
				bt.add(L[x],-PDS[x]);
				bt.add(R[x],+PDS[x]);
				PDS[x]=q[3];
				bt.add(L[x],PDS[x]);
				bt.add(R[x],-PDS[x]);
			}
			else {
				ret.push_back(bt(L[q[1]-1]));
			}
		}
		return ret;
    }
};
