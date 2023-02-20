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

vector<int> P={2,3,5,7,11,13,17,19,23,29};
ll dp[1<<10];
const ll mo=1000000007;
int mask[33];

class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        
        int i,j;
        for(i=2;i<=30;i++) {
			mask[i]=0;
			FOR(j,P.size()) {
				if(i%(P[j]*P[j])==0) {
					mask[i]=-1;
					break;
				}
				if(i%P[j]==0) {
					mask[i]|=1<<j;
				}
			}
		}
		ZERO(dp);
		dp[0]=1;
		FORR(n,nums) if(mask[n]!=-1) {
			for(i=(1<<10)-1;i>=0;i--) if((i&mask[n])==0) (dp[i|mask[n]]+=dp[i])%=mo;
		}
		
		ll ret=mo-1;
		FOR(i,1<<10) ret+=dp[i];
		return ret%mo;
		
        
    }
};

