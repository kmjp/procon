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

int win[1010];

class Solution {
public:
    bool divisorGame(int N) {
        ZERO(win);
        int i,j;
        for(int i=2;i<=N;i++) {
			for(j=1;j<i;j++) if(i%j==0 && win[i-j]==0) win[i]=1;
		}
        return win[N];
        
    }
};

