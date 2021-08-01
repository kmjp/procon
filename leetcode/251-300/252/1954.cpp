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
    long long minimumPerimeter(long long neededApples) {
		for(ll a=1;a<=10000000;a++) {
			ll sum=a*(a+1)*(2*a+1)*2;
			
			if(sum>=neededApples) return a*8;
			
		}
		return -1;
        
    }
};
