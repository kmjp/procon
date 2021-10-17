typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))

//-------------------------------------------------------


int N;
vector<int> E[202020];
ll dp[202020];

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
		N=patience.size();
		int i;
		FOR(i,N) E[i].clear(),dp[i]=1<<30;
		FORR(a,edges) {
			E[a[0]].push_back(a[1]);
			E[a[1]].push_back(a[0]);
		}
        queue<int> Q;
        dp[0]=0;
        Q.push(0);
        ll ma=0;
        while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			FORR(e,E[cur]) if(dp[e]>dp[cur]+1) {
				dp[e]=dp[cur]+1;
				Q.push(e);
			}
		}
		for(i=1;i<N;i++) {
			ll f=2*dp[i];
			ll la=(f-1)/patience[i]*patience[i];
			ma=max(ma,la+f);
		}
		return ma+1;
    }
};
