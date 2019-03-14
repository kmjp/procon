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


int C[22020];

class Solution {
public:
    int clumsy(int N) {
		ll ret=0;
		int first=1;
		while(N>0) {
			if(N==1) ret+=(first?1:-1);
			else if(N==2) ret+=(first?2:-2);
			else if(N==3) ret+=(first?6:-6);
			else {
				ret+=first?(1LL*N*(N-1)/(N-2)+(N-3)):(-1LL*N*(N-1)/(N-2)+(N-3));
			}
			first=0;
			N-=4;
		}
		return ret;
        
    }
};
