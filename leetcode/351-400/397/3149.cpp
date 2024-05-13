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

int dp[1<<14][14];
int nex[1<<14][14];

class Solution {
public:
	vector<int> nums;
	int N;
	
	int dfs(int mask,int p) {
		if(mask+1==1<<N) return abs(p-nums[0]);
		if(dp[mask][p]==1<<30) {
			int i;
			FOR(i,N) if((mask&(1<<i))==0) {
				int ret=abs(p-nums[i])+dfs(mask|(1<<i),i);
				if(ret<dp[mask][p]) {
					dp[mask][p]=ret;
					nex[mask][p]=i;
				}
			}
		}
		return dp[mask][p];
	}
    vector<int> findPermutation(vector<int>& nums) {
        
        int mask,i,j,x,y;
        N=nums.size();
        this->nums=nums;
        FOR(mask,1<<N) FOR(i,N) dp[mask][i]=1<<30;
        
        dfs(1,0);
        vector<int> ret={0};
        mask=1;
        while(mask+1<1<<N) {
			int n=nex[mask][ret.back()];
			ret.push_back(n);
			mask|=1<<n;
		}
        
        return ret;
        
    }
};
