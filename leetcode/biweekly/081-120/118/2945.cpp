#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
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

ll S[101010];

int pre[202020];
int dp[202020];

class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
		int N=nums.size();
		int i;
		FOR(i,N) S[i+1]=S[i]+nums[i];
		FOR(i,N+2) dp[i]=pre[i]=0;
		for(i=1;i<=N;i++) {
			pre[i]=max(pre[i],pre[i-1]);
			dp[i]=dp[pre[i]]+1;
			int n=lower_bound(S,S+N+1,S[i]*2-S[pre[i]])-S;
			pre[n]=i;
		}
		return dp[N];
		
        
    }
};
