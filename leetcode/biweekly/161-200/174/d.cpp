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

int V[101010];
vector<pair<int,int>> E[101010];
vector<int> ret;
class Solution {
public:
	int dfs(int cur,int pre) {
		FORR2(e,i,E[cur]) if(e!=pre) {
			int v=dfs(e,cur);
			if(v) {
				V[e]^=1;
				V[cur]^=1;
				ret.push_back(i);
			}
		}
		return V[cur];
	}
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
		int i;
		FOR(i,n) {
			E[i].clear();
			V[i]=start[i]!=target[i];
		}
		FOR(i,edges.size()) {
			auto a=edges[i];
			E[a[0]].push_back({a[1],i});
			E[a[1]].push_back({a[0],i});
		}
		ret.clear();
		if(dfs(0,0)) {
			return {-1};
		}
		else {
			sort(ALL(ret));
			return ret;
		}
        
    }
};


