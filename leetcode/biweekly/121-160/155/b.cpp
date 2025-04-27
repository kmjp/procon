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
vector<int> ret;
const ll mo=1000000007;

class Solution {
public:
	void dfs(int cur,int pre,ll a) {
		ret[cur]=a;
		FORR(e,E[cur]) if(e.first!=pre) dfs(e.first,cur,a*e.second%mo);
	}
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
		int N=conversions.size()+1;
		int i;
		FOR(i,N) E[i].clear();
		FORR(a,conversions) {
			E[a[0]].push_back({a[1],a[2]});
			E[a[1]].push_back({a[0],a[2]});
		}
		ret.clear();
		ret.resize(N);
		dfs(0,0,1);
		return ret;
        
    }
};

