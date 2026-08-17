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


ll dp[1<<16][16];

class Solution {
public:
    long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
		int i,j;
		int mask;
		int N=requests.size();
		
		FOR(mask,1<<N) FOR(i,N) dp[mask][i]=1LL<<60;
		FOR(i,N) dp[1<<i][i]=max(requests[i][0],abs(start-requests[i][1]));
		
		ll ret=1LL<<60;
		FOR(mask,1<<N) FOR(i,N) if(mask&(1<<i)) {
			FOR(j,N) if((mask&(1<<j))==0) chmin(dp[mask|(1<<j)][j],max((ll)requests[j][0],dp[mask][i]+abs(requests[i][1]-requests[j][1])));
			if(mask==(1<<N)-1) ret=min(ret,dp[mask][i]);
		}
		return ret;
		
        
    }
};


