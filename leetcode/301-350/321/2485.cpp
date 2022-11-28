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
    int pivotInteger(int n) {
		
		for(int i=1;i<=n;i++) {
			int a=i*(i+1)/2;
			int b=n*(n+1)/2-i*(i-1)/2;
			if(a==b) return i;
		}
        return -1;
    }
};

