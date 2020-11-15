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

int S[1024];
int dp[1024];

class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        map<int,int> M;
        FORR(n,nums) M[n]++;
        
        int mask,mask2;
        int i;
        int N=quantity.size();
        FOR(mask,1<<N) {
			S[mask]=0;
			FOR(i,N) if(mask&(1<<i)) S[mask]+=quantity[i];
		}
		
		ZERO(dp);
		dp[0]=1;
		FORR(m,M) {
			for(mask=(1<<N)-1;mask>=0;mask--) if(dp[mask]) {
				int oth=((1<<N)-1)^mask;
				for(mask2=oth; mask2>0; mask2=(mask2-1)&oth) {
					if(S[mask2]<=m.second) dp[mask2|mask]=1;
				}
				
			}
		}
		
		
		
		
        return dp[(1<<N)-1];
        
    }
};
