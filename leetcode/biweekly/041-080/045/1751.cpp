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

vector<ll> dp[2101010];
vector<int> cand[2101010];
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
		vector<ll> X;
		X.push_back(0);
		FORR(e,events) {
			X.push_back(e[0]);
			X.push_back(e[1]+1);
		}
		sort(ALL(X));
		X.erase(unique(ALL(X)),X.end());
        int n=events.size();
        int i,j;
        FOR(i,X.size()+2) dp[i].clear(), dp[i].resize(k+1,-(1LL<<60));
        FOR(i,X.size()+1) cand[i].clear();
        FOR(i,n) {
			events[i][0]=lower_bound(ALL(X),events[i][0])-X.begin();
			events[i][1]=lower_bound(ALL(X),events[i][1]+1)-X.begin();
			cand[events[i][0]].push_back(i);
		}
		ll ma=0;
		dp[0][k]=0;
		FOR(i,X.size()) {
			FOR(j,k+1) dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			FORR(c,cand[i]) {
				int a=events[c][1];
				for(j=1;j<=k;j++) {
					dp[a][j-1]=max(dp[a][j-1],dp[i][j]+events[c][2]);
					ma=max(ma,dp[a][j-1]);
				}
			}
		}
		return ma;
        
    }
};
