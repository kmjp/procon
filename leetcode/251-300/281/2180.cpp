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
    int countEven(int num) {
		int i;
		int ret=0;
		for(i=1;i<=num;i++) {
			int a=i,b=0;
			while(a) b+=a%10,a/=10;
			if(b%2==0) ret++;
		}
		return ret;
        
    }
};
