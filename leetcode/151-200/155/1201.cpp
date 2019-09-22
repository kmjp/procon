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

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        ll ret=1LL<<40;
        ll ab=1LL*a*b/__gcd(a,b);
        ll ac=1LL*a*c/__gcd(a,c);
        ll bc=1LL*b*c/__gcd(b,c);
        ll abc=1LL*ab*c/__gcd(ab,(ll)c);
        
        for(int i=39;i>=0;i--) {
			ll tmp=ret-(1LL<<i);
			ll num=tmp/a+tmp/b+tmp/c-tmp/ab-tmp/ac-tmp/bc+tmp/abc;
			if(num>=n) ret=tmp;
			
		}
        return ret;
    }
};
