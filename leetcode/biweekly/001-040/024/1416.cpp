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


string K;
ll dp[101010];
const ll mo=1000000007;

class Solution {
public:
    int numberOfArrays(string s, int k) {
		string K=to_string(k);
		int L=K.size();
		int N=s.size();
		ZERO(dp);
		dp[0]=1;
		int i;
		
		FOR(i,s.size()) {
			if(s[i]=='0') continue;
			for(int len=1;len<=L && i+len<=N;len++) {
				if(len<L) (dp[i+len]+=dp[i])%=mo;
				else if(s.substr(i,len)<=K) (dp[i+len]+=dp[i])%=mo;
			}
		}
		return dp[N];
        
    }
};


