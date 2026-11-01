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

int N;
vector<pair<int,int>> E[101010];
vector<int> V;
ll ret;
class Solution {
public:
	pair<ll,ll> dfs(int cur,int pre) {
		vector<ll> A[2];
		FORR2(e,c,E[cur]) if(e!=pre) {
			auto p=dfs(e,cur);
			A[0].push_back(p.first+c);
			A[1].push_back(p.second+c);
		}
		A[0].push_back(1LL<<60);
		A[0].push_back(1LL<<60);
		A[1].push_back(1LL<<60);
		A[1].push_back(1LL<<60);
		if(__builtin_popcount(V[cur])%2==0) {
			A[0].push_back(0);
			sort(ALL(A[0]));
			sort(ALL(A[1]));
			ret=min(ret,A[0][0]+A[0][1]);
			ret=min(ret,A[1][0]+A[1][1]);
			return {A[0][0],A[1][0]};
		}
		else {
			sort(ALL(A[0]));
			sort(ALL(A[1]));
			ret=min(ret,A[1][0]);
			return {A[1][0],0};
		}
	}

    int minActivationCost(vector<vector<int>>& edges, vector<int>& values) {
		V=values;
        N=values.size();
        int i;
        FOR(i,N) E[i].clear();
        FORR(e,edges) {
			E[e[0]].push_back({e[1],e[2]});
			E[e[1]].push_back({e[0],e[2]});
		}
		ret=1LL<<60;
		
		dfs(0,0);
		
		if(ret==1LL<<60) return -1;
		return ret;
		
        
    }
};


