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
int in[303030];
ll dp[202020];

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int N=online.size();
        int i,j;
        
        int ret=-1;
        for(i=30;i>=0;i--) {
			int tmp=ret+(1<<i);
			FOR(j,N) {
				E[j].clear();
				in[j]=0;
			}
			FORR(e,edges) if(online[e[0]]&&online[e[1]]&&e[2]>=tmp) {
				E[e[0]].push_back({e[1],e[2]});
				in[e[1]]++;
			}
			queue<int> Q;
			FOR(j,N) {
				dp[j]=1LL<<60;
				if(in[j]==0) Q.push(j);
			}
			dp[0]=0;
			while(Q.size()) {
				int cur=Q.front();
				Q.pop();
				FORR(e,E[cur]) {
					chmin(dp[e.first],dp[cur]+e.second);
					in[e.first]--;
					if(in[e.first]==0) Q.push(e.first);
				}
			}
			if(dp[N-1]<=k) ret=tmp;
			
		}
		return ret;
        
        
    }
};
