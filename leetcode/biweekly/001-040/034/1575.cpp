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

ll dp[201][202];
const ll mo=1000000007;
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
		ZERO(dp);
		dp[fuel][start]=1;
		int N=locations.size();
		int f,x,y;
		ll ret=0;
		for(f=fuel;f>=0;f--) {
			FOR(x,N) FOR(y,N) if(x!=y && abs(locations[x]-locations[y])<=f) (dp[f-abs(locations[x]-locations[y])][y]+=dp[f][x])%=mo;
			ret+=dp[f][finish];
		}
        return ret%mo;
    }
};
