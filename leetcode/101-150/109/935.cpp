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

ll dp[5050][10];
ll mo=1000000007;

class Solution {
public:
	int knightDialer(int N) {
		vector<int> T[10];
		T[0]={4,6};
		T[1]={6,8};
		T[2]={7,9};
		T[3]={4,8};
		T[4]={3,9,0};
		T[5]={};
		T[6]={1,7,0};
		T[7]={2,6};
		T[8]={1,3};
		T[9]={2,4};
		ZERO(dp);
		int i,j;
		FOR(i,10) dp[1][i]=1;
		for(j=2;j<=N;j++) {
			FOR(i,10) FORR(t,T[i]) (dp[j][t]+=dp[j-1][i])%=mo;
		}
		
		ll tot=0;
		FOR(i,10) tot+=dp[N][i];
		return tot%mo;
		
	}
};
