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

vector<int> E[202020];
vector<int> B;

class Solution {
public:
	ll dfs(int cur,int pre) {
		vector<ll> V;
		FORR(e,E[cur]) if(e!=pre) V.push_back(dfs(e,cur));
		
		if(V.empty()) {
			return B[cur];
		}
		else {
			sort(ALL(V));
			return V.back()-V[0]+B[cur]+V.back();
		}
		
	}
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
		int i;
		FOR(i,n) E[i].clear();
		B=baseTime;
		FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
		}
		return dfs(0,0);
		
        
    }
};
