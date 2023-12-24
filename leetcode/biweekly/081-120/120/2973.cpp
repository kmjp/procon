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


vector<ll> P[101010],M[101010];
vector<int> E[101010];
vector<ll> R;

class Solution {
public:
	void dfs(int cur,int pre) {
		FORR(e,E[cur]) if(e!=pre) {
			dfs(e,cur);
			FORR(p,P[e]) P[cur].push_back(p);
			FORR(p,M[e]) M[cur].push_back(p);
		}
		sort(ALL(P[cur]));
		sort(ALL(M[cur]));
		if(P[cur].size()>6) P[cur]={P[cur][0],P[cur][1],P[cur][2],P[cur][P[cur].size()-3],P[cur][P[cur].size()-2],P[cur][P[cur].size()-1]};
		if(M[cur].size()>6) M[cur]={M[cur][0],M[cur][1],M[cur][2],M[cur][M[cur].size()-3],M[cur][M[cur].size()-2],M[cur][M[cur].size()-1]};
		vector<ll> C;
		FORR(p,P[cur]) C.push_back(p);
		FORR(p,M[cur]) C.push_back(p);
		if(C.size()<3) {
			R[cur]=1;
		}
		else {
			R[cur]=0;
			int a,b,c;
			FOR(a,C.size()) FOR(b,a) FOR(c,b) R[cur]=max(R[cur],C[a]*C[b]*C[c]);
		}
	}
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
		int i;
		int N=cost.size();
		FOR(i,N) {
			E[i].clear(),P[i].clear(),M[i].clear();
			if(cost[i]>=0) P[i].push_back(cost[i]);
			if(cost[i]<0) M[i].push_back(cost[i]);
		}
		FORR(e,edges) E[e[0]].push_back(e[1]),E[e[1]].push_back(e[0]);
		R.resize(N);
		dfs(0,0);
		return R;
		
        
    }
};
