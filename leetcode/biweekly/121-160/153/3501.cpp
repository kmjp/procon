#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

ll A[1010];
ll C[1010];
ll dp[1010];

class Solution {
public:
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
		int N=nums.size();
		int i,x,y;
		reverse(ALL(nums));
		reverse(ALL(cost));
		FOR(i,N) A[i+1]=A[i]+nums[i], C[i+1]=C[i]+cost[i];
		FOR(i,N+1) dp[i]=1LL<<60;
		dp[0]=0;
		FOR(i,N) {
			cout<<i<<" "<<dp[i]<<endl;
			for(x=1;i+x<=N;x++) {
				chmin(dp[i+x],dp[i]+C[i+x]*k+(C[i+x]-C[i])*(A[N]-A[i]));
			}
		}
		return dp[N];
		
		
        
    }
};
