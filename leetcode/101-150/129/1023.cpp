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

int memo[11][1<<10][2][2];


class Solution {
public:
	ll N;
	int hoge(int d,int mask,int lim,int lead,ll p10) {
		if(d==-1) return 1;
		if(memo[d][mask][lim][lead]>=0) return memo[d][mask][lim][lead];
		
		ll ret=0;
		
		int i;
		int ma=10;
		if(lim) ma=N/p10%10;
		FOR(i,ma) {
			if(lead&&i==0) {
				ret+=hoge(d-1,mask,0,1,p10/10);
			}
			else if((mask&(1<<i))==0) {
				ret+=hoge(d-1,mask^(1<<i),0,0,p10/10);
			}
		}
		if(ma<10) {
			if(lead==1 && ma==0) {
				ret+=hoge(d-1,mask,1,1,p10/10);
			}
			else if((mask&(1<<ma))==0) {
				ret+=hoge(d-1,mask|(1<<ma),1,0,p10/10);
			}
		}
		return memo[d][mask][lim][lead]=ret;
	}
    int numDupDigitsAtMostN(int N) {
        MINUS(memo);
        this->N=N;
        return N+1-hoge(10,0,1,1,10000000000LL);
    }
};

