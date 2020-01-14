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
    int minFlips(int a, int b, int c) {
        int i;
        int ret=0;
        FOR(i,31) {
			if(((a%2)|(b%2))!=(c%2)) {
				if(c%2==1) ret++;
				else {
					ret+=a%2+b%2;
				}
			}
			a/=2;
			b/=2;
			c/=2;
		}
        return ret;
    }
};
