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

class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
		int N=nums.size();
		int C[4040]={};
		FORR(v,nums) C[v]++;
		int dp[4040]={};
		int i,x,j;
		int lef=N;
		dp[0]=1;
		vector<bool> ret;
		for(i=1;i<=N;i++) {
			FOR(j,C[i]) {
				lef--;
				for(x=k;x>=i;x--) dp[x]|=dp[x-i];
			}
			int ok=0;
			FOR(x,k+1) if(dp[x]&&(k-x)%i==0&&(k-x)/i<=lef) ok=1;
			ret.push_back(ok);
		}
        return ret;
    }
};


