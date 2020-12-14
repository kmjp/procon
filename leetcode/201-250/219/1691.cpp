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

int dp[101];

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
		int i,j;
		int N=cuboids.size();
		FORR(c,cuboids) sort(ALL(c));
        sort(ALL(cuboids));
        FOR(i,N) dp[i]=cuboids[i][2];
        int ma=0;
        FOR(i,N) {
			for(j=i+1;j<N;j++) {
				if(cuboids[i][0]>cuboids[j][0]) continue;
				if(cuboids[i][1]>cuboids[j][1]) continue;
				if(cuboids[i][2]>cuboids[j][2]) continue;
				dp[j]=max(dp[j],dp[i]+cuboids[j][2]);
			}
			ma=max(ma,dp[i]);
		}
        return ma;
        
    }
};
