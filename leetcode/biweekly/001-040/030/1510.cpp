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

int memo[101010];

class Solution {
public:
	int win(int n) {
		if(n==0) return 0;
		if(memo[n]>=0) return memo[n];
		
		int i;
		for(i=1;i*i<=n;i++) if(win(n-i*i)==0) return memo[n]=1;
		return memo[n]=0;
		
	}

    bool winnerSquareGame(int n) {
		MINUS(memo);
        
        return win(n);
        
    }
};

