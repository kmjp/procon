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

int mask[31];

const int prime_max = 30;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

ll dp[1<<10];
const ll mo=1000000007;

class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
		
		cprime();
		int i,j;
		for(i=1;i<=30;i++) {
			mask[i]=0;
			FOR(j,prime.size()) {
				int cur=i;
				int num=0;
				while(cur%prime[j]==0) cur/=prime[j], num++;
				if(num>1) {
					mask[i]=-1;
					break;
				}
				if(num==1) mask[i]|=1<<j;
			}
		}
		
		ZERO(dp);
		int C[31]={};
		int x;
		FORR(x,nums) C[x]++;
		dp[0]=1;
		FOR(i,C[1]) dp[0]=dp[0]*2%mo;
		
		for(j=2;j<=30;j++) if(mask[j]!=-1&&C[j]) {
			FOR(i,1<<10) if((i&mask[j])==0) (dp[i|mask[j]]+=dp[i]*C[j])%=mo;
		}
        ll ret=0;
        FOR(i,1<<10) if(i) ret+=dp[i];
        return ret%mo;
    }
};
