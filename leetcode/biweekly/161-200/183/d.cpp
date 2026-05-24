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

ll dp[1010][2][101];
vector<int> E[2020];
const ll mo=1000000007;

class Solution {
public:
    int countValidSubsets(vector<int>& parent, vector<int>& nums, int k) {
        ZERO(dp);
        int N=nums.size();
        int i,j,x,y;
        FOR(i,N) E[i].clear();
        for(i=N-1;i>=0;i--) {
			ll from[2][101]={},to[2][101];
			from[0][0]=1;
			from[1][nums[i]%k]=1;
			FORR(e,E[i]) {
				ZERO(to);
				FOR(x,k) FOR(y,k) {
					(to[0][(x+y)%k]+=from[0][x]*(dp[e][0][y]+dp[e][1][y]))%=mo;
					(to[1][(x+y)%k]+=from[1][x]*(dp[e][0][y]))%=mo;
				}
				
				swap(from,to);
			}
			FOR(j,k) {
				dp[i][0][j]=from[0][j];
				dp[i][1][j]=from[1][j];
			}
			if(i) E[parent[i]].push_back(i);
		}
		
		return (dp[0][0][0]+dp[0][1][0]+mo-1)%mo;
        
    }
};


