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

ll dp[1010];
int C[1010];
class Solution {
public:
    int minCost(vector<int>& nums, int k) {
		int N=nums.size();
        int i,j;
        FOR(i,N+1) dp[i]=1LL<<60;
        dp[0]=0;
        
        FOR(i,N) {
			ZERO(C);
			int O=0;
			for(j=i;j<N;j++) {
				int x=nums[j];
				if(C[x]>=2) {
					C[x]++;
				}
				else if(C[x]==1) {
					C[x]++;
					O--;
				}
				else {
					C[x]++;
					O++;
				}
				dp[j+1]=min(dp[j+1],dp[i]+k+(j-i+1)-O);
			}
		}
        
        return dp[N];
    }
};
