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

ll dp[101010];
ll S[101010];
const ll mo=1000000007;
class Solution {
public:
    int numberOfWays(string corridor) {
        int N=corridor.size();
        S[1]=1;
        vector<int> T;
        T={0,0,0};
        int i;
        for(i=1;i<=N;i++) {
			if(corridor[i-1]=='S') T.push_back(i);
			int L=T[T.size()-3];
			int R=T[T.size()-2];
			
			dp[i]=(S[R]-S[L]+mo)%mo;
			S[i+1]=(S[i]+dp[i])%mo;
		}
        return dp[N];
        
    }
};
