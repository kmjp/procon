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

ll memo[1<<10][10][2];
int N;

class Solution {
public:
	ll dfs(int mask,int d,int le) {
		if(d<0) return 1;
		if(memo[mask][d][le]>=0) return memo[mask][d][le];
		ll ret=0;
		int i;
		int v=N;
		FOR(i,d) v/=10;
		v%=10;
		FOR(i,10) {
			if(le==0&&i>v) continue;
			if((mask&(1<<i))==0) continue;
			int nmask=mask;
			if(i||mask!=1023) nmask^=1<<i;
			ret+=dfs(nmask,d-1,le||(i<v));
		}
		return memo[mask][d][le]=ret;
	}
	
    int countSpecialNumbers(int n) {
        MINUS(memo);
        N=n;
        return dfs(1023,9,0)-1;
    }
};
