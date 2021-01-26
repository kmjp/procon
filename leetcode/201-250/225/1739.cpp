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
    int minimumBoxes(int n) {
		for(int i=1;i<=100000;i++) {
			ll cur=i*(i+1)/2;
			if(n<=cur) {
				for(int j=1;j<=i;j++) {
					if(n<=1LL*j*(j+1)/2) return i*(i-1)/2+j;
				}
				
			}
			else n-=cur;
		}
		return -1;
		
        
    }
};
