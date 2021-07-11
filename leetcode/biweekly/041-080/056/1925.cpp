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
    int countTriples(int n) {
		int a,b,c;
		int ret=0;
		for(c=1;c<=n;c++) {
			for(a=1;a<c;a++) {
				for(b=1;a*a+b*b<=c*c;b++) {
					ret+=a*a+b*b==c*c;
				}
			}
		}
		return ret;
		
        
    }
};

