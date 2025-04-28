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


int p10[10];
int D[20];
vector<int> dp[1<<13][100];

class Solution {
public:
    vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
        sort(ALL(nums));
        int N=nums.size();
        int i,j;
        p10[0]=1;
        FOR(i,8) p10[i+1]=p10[i]*10;
        FOR(i,nums.size()) {
			D[i]=0;
			while(nums[i]>=p10[D[i]+1]) D[i]++;
			D[i]++;
		}
		int mask;
		FOR(mask,1<<N) FOR(i,k) dp[mask][i].clear();
		FOR(i,N) dp[1<<i][nums[i]%k]={nums[i]};
		FOR(mask,1<<N) FOR(i,k) if(dp[mask][i].size()) {
			FOR(j,N) if((mask&(1<<j))==0) {
				int nd=(i*p10[D[j]]+nums[j])%k;
				vector<int> nv=dp[mask][i];
				nv.push_back(nums[j]);
				if(dp[mask^(1<<j)][nd].empty()) dp[mask^(1<<j)][nd]=nv;
				dp[mask^(1<<j)][nd]=min(dp[mask^(1<<j)][nd],nv);
			}
		}
	    return dp[(1<<N)-1][0];
    }
};
