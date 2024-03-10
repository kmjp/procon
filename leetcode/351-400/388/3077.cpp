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


int N;
ll S[101010];

ll dp[10101];

class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {
        N=nums.size();
        int i,j;
        FOR(i,N) S[i+1]=S[i]+nums[i];
        
        FOR(i,N+1) dp[i]=0;
		while(k) {
			// add
			{
				ll ma=-1LL<<60;
				for(i=0;i<=N;i++) {
					ll nma=max(ma,dp[i]);
					ll add=0;
					
					if(k%2) {
						add=-S[i]*k;
					}
					else {
						add=S[i]*k;
					}
					ma=nma;
					dp[i]=ma+add;
				}
			}
			// del
			{
				ll ma=-1LL<<60;
				for(i=0;i<=N;i++) {
					ll nma=max(ma,dp[i]);
					ll add=0;
					
					if(k%2==1) {
						add=S[i]*k;
					}
					else {
						add=-S[i]*k;
					}
					dp[i]=ma+add;
					ma=nma;
				}
			}
			
			k--;
			
		}
        return *max_element(dp,dp+N+1);
        
        
    }
};
