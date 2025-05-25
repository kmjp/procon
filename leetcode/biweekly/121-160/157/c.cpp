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


int D[202020];
vector<int> E[202020];
const ll mo=1000000007;

class Solution {
public:
	int dfs(int cur,int pre,int d) {
		int ret=d;
		FORR(e,E[cur]) if(e!=pre) ret=max(ret,dfs(e,cur,d+1));
		return ret;
	}
    int assignEdgeWeights(vector<vector<int>>& edges) {
		int N=edges.size()+1;
		int i;
		FOR(i,N) E[i].clear();
		FORR(e,edges) {
			E[e[0]-1].push_back(e[1]-1);
			E[e[1]-1].push_back(e[0]-1);
		}
		int d=dfs(0,0,0);
		ll ret=1;
		cout<<d<<endl;
		FOR(i,d-1) ret=ret*2%mo;
		return ret;
        
    }
};

