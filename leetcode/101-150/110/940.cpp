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
    int distinctSubseqII(string S) {
		int N=S.size();
		ll dp[2020]={};
		ll mo=1000000007;
		dp[0]=1;
		int i,j;
		ll ret=0;
		FOR(i,N+1) {
			int cnt[26]={};
			if(i) ret+=dp[i];
			for(j=i;j<N;j++) if(cnt[S[j]-'a']++==0) (dp[j+1]+=dp[i])%=mo;
		}
		return ret%mo;
        
    }
};

