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


ll S[2][101010];
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
		int N=grid[0].size();
		int i;
		FOR(i,N) {
			S[0][i+1]=S[0][i]+grid[0][i];
			S[1][i+1]=S[1][i]+grid[1][i];
		}
		if(N==1) return 0;
		ll ret=1LL<<60;
		FOR(i,N) {
			ll r=S[0][N]-S[0][i+1];
			ll l=S[1][i];
			ret=min(ret,max(l,r));
		}
		return ret;
        
    }
};
