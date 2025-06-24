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

ll C[101010];
vector<int> E[101010];
ll ret;
class Solution {
public:
	ll dfs(int cur,int pre) {
		ll ma=0;
		FORR(e,E[cur]) if(e!=pre) ma=max(ma,dfs(e,cur));
		C[cur]+=ma;
		FORR(e,E[cur]) if(e!=pre&&C[e]!=ma) ret++;
		return C[cur];
	}

    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        int i;
        FOR(i,n) C[i]=cost[i];
        FOR(i,n) E[i].clear();
        FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
		}
		ret=0;
		dfs(0,0);
		return ret;
    }
};


