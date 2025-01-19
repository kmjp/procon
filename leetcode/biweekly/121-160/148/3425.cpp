#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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


vector<pair<int,int>> E[505050];
int A[505050];
vector<int> V[505050];
int D[505050];
int DL[505050];
int len;
int nodes;

vector<int> Ds;

class Solution {
public:
	void dfs(int cur,int pre,int dl,int ma) {
		Ds.push_back(dl);
		if(V[A[cur]].size()) {
			ma=max(ma,V[A[cur]].back());
		}
		V[A[cur]].push_back(Ds.size()-1);
		
		ll tl=dl-Ds[ma+1];
		int tnodes=Ds.size()-(ma+1);
		if(tl>len) {
			len=tl;
			nodes=tnodes;
		}
		if(tl==len) nodes=min(nodes,tnodes);
		FORR(e,E[cur]) if(e.first!=pre) dfs(e.first,cur,dl+e.second,ma);
		
		
		V[A[cur]].pop_back();
		Ds.pop_back();
		
		
	}
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int N=edges.size()+1;
        int i;
        FOR(i,N) {
			E[i].clear();
			A[i]=nums[i];
		}
		FORR(e,edges) {
			E[e[0]].push_back({e[1],e[2]});
			E[e[1]].push_back({e[0],e[2]});
		}
		len=0,nodes=1;
		dfs(0,0,0,-1);
		return {(int)len,(int)nodes};
    }
};
