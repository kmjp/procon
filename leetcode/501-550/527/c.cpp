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

int C[101010];
vector<int> E[101010];
int ret;
ll AB[101010];
ll AR[101010];
ll SR[101010];



class Solution {
public:
	int dfs(int cur,int pre) {
		int V=1;
		FORR(e,E[cur]) if(e!=pre) V+=dfs(e,cur);
		
		
		AB[cur]=C[cur]?V:0;
		FORR(e,E[cur]) if(e!=pre) AB[cur]+=AB[e];
		
		ll sum=C[cur]?V:0;
		SR[cur]=1LL<<60;
		FORR(e,E[cur]) if(e!=pre) {
			sum+=AB[e];
			SR[cur]=min(SR[cur],SR[e]-AB[e]);
			SR[cur]=min(SR[cur],AR[e]-AB[e]);
		}
		SR[cur]=min(1LL<<60,SR[cur]+sum);
		
		AR[cur]=C[cur]?0:V;
		FORR(e,E[cur]) if(e!=pre) AR[cur]+=min(AR[e],AB[e]);
		
		return V;
		
		
	}
    long long minCost(int n, string colors, vector<vector<int>>& edges) {
        int i;
        FOR(i,n) C[i]=colors[i]=='R';
        FOR(i,n) E[i].clear();
        FORR(e,edges) E[e[0]].push_back(e[1]),E[e[1]].push_back(e[0]);
        
        dfs(0,0);
        return min({AB[0],AR[0],SR[0]});
        
        
        
    }
};

