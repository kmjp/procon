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

int dp[303][303];
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
		ZERO(dp);
		reverse(ALL(nums));
		int pre;
		FORR(a,nums) {
			for(pre=1;pre<=300;pre++) {
				int d=abs(a-pre);
				dp[a][d]=max(dp[a][d],dp[pre][d]+1);
			}
			for(int i=1;i<=300;i++) dp[a][i]=max(dp[a][i],dp[a][i-1]);
		}
        int ret=0;
        int a,b;
        FOR(a,301) FOR(b,301) ret=max(ret,dp[a][b]);
        return ret;
    }
};


 