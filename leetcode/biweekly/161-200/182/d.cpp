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
int dp[202020];
class Solution {
public:
	int ok(int S,int T,int n) {
		int i;
		FOR(i,n) dp[i]=1<<20;
		dp[S]=0;
		deque<int> Q;
		Q.push_back(S);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop_front();
			if(cur==T) return dp[cur];
			FORR2(e,c,E[cur]) if(chmin(dp[e],dp[cur]+c)) {
				if(c==0) Q.push_front(e);
				else Q.push_back(e);
			}
				
		}
		return 1<<20;
		
		
	}

    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
		int i,j;
		FOR(i,n) E[i].clear();
		FORR(e,edges) {
			E[e[0]].push_back({e[1],0});
			E[e[1]].push_back({e[0],0});
		}
		if(ok(source,target,n)>n) return -1;
		int ret=(1<<30)-1;
		for(j=29;j>=0;j--) {
			FOR(i,n) E[i].clear();
			FORR(e,edges) {
				E[e[0]].push_back({e[1],e[2]>ret-(1<<j)});
				E[e[1]].push_back({e[0],e[2]>ret-(1<<j)});
			}
			if(ok(source,target,n)<=k) ret-=1<<j;
		}
		return ret;
        
    }
};
