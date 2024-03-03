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


vector<pair<int,int>> E[1010];


class Solution {
public:
	int s;
	int dfs(int cur,int pre,int c) {
		int ret=0;
		if(c%s==0) ret++;
		FORR(e,E[cur]) if(e.first!=pre) ret+=dfs(e.first,cur,c+e.second);
		return ret;
	}
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int N=edges.size()+1;
        s=signalSpeed;
        int i;
        FOR(i,N) E[i].clear();
        FORR(a,edges) {
			E[a[0]].push_back({a[1],a[2]});
			E[a[1]].push_back({a[0],a[2]});
		}
		vector<int> V;
		FOR(i,N) {
			int sum=0;
			int num=0;
			FORR(e,E[i]) {
				int ret=dfs(e.first,i,e.second);
				sum+=ret*num;
				num+=ret;
			}
			V.push_back(sum);
		}
		return V;
        
    }
};
