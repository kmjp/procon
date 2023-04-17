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

vector<int> E[55];
int P[1010];
int S[1010];
int D[55][55];

class Solution {
public:
	pair<int,int> dfs(int cur,int pre) {
		int p0=S[cur]/2;
		int p1=S[cur];
		
		FORR(e,E[cur]) if(e!=pre) {
			auto p=dfs(e,cur);
			p0=p0+p.second;
			p1=min(p1+p.first,p1+p.second);
		}
		return {p0,p1};
		
	}

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
		int i;
		FOR(i,n) {
			E[i].clear();
			S[i]=0;
		}
		int x,y;
		FOR(x,n) FOR(y,n) D[x][y]=(x==y)?0:10000;
		FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
			D[e[0]][e[1]]=D[e[1]][e[0]]=1;
		}
		FOR(i,n) FOR(x,n) FOR(y,n) D[x][y]=min(D[x][y],D[x][i]+D[i][y]);
		FORR(e,trips) {
			FOR(i,n) if(D[e[0]][i]+D[e[1]][i]==D[e[0]][e[1]]) S[i]+=price[i];
		}
		
		auto p=dfs(0,0);
		return min(p.first,p.second);
        
    }
};
