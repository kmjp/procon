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

ll D[101];
class Solution {
public:
    int getMaximumGenerated(int n) {
        D[0]=0;
        D[1]=1;
        ll ma=0;
        if(n) ma=1;
        int i;
        for(i=2;i<=n;i++) {
			if(i%2==0) D[i]=D[i/2];
			else D[i]=D[i/2]+D[i/2+1];
			ma=max(ma,D[i]);
		}
		return ma;
    }
};

