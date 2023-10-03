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

int E[202020];
int vis[202020];

class Solution {
public:
	pair<int,int> dfs(int cur,int d) {
		if(vis[cur]>=0) {
			return {-1,vis[cur]};
		}
		else if(vis[cur]<=-100000) {
			vis[cur]=d-vis[cur]-10000000;
			return {cur,vis[cur]};
		}
		else {
			vis[cur]=-10000000+d;
			auto p=dfs(E[cur],d+1);
			if(p.first==cur) {
				p.first=-1;
				return p;
			}
			else if(p.first>=0) {
				vis[cur]=p.second;
				return p;
			}
			else {
				vis[cur]=++p.second;
				return p;
			}
		}
	}
    vector<int> countVisitedNodes(vector<int>& edges) {
        int N=edges.size();
        int i;
        FOR(i,N) E[i]=edges[i];
        FOR(i,N) vis[i]=-1;
        FOR(i,N) if(vis[i]==-1) dfs(i,0);
        vector<int> R;
        FOR(i,N) R.push_back(vis[i]);
        return R;
    }
};


