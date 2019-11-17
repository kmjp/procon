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

int memo[1010];
ll mo=1000000007;

class Solution {
public:
    int numberOfWays(int N) {
		if(N==0 || N==2) return 1;
		if(N%2==1) return 0;
		if(memo[N]>0) return memo[N];
		
		ll ret=0;
		
		int i;
		for(i=1;i<N;i+=2) ret+=1LL*numberOfWays(i-1)*numberOfWays(N-i-1)%mo;
		
		cout<<N<<" "<<ret<<endl;
		return memo[N]=ret%mo;
    }
};



