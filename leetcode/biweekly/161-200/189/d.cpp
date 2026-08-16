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


ll dp[2020][2020][2];

class Solution {
public:
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        vector<int> A,B;
        FORR(a,requests) {
			if(a>start) A.push_back(a-start);
			if(a<start) B.push_back(start-a);
		}
		A.push_back(0);
		sort(ALL(A));
		sort(ALL(B));
		int N=A.size(),M=B.size();
		int x,y;
		FOR(x,N+1) FOR(y,M+1) dp[x][y][0]=dp[x][y][1]=1LL<<60;
		dp[1][0][0]=0;
		
		for(x=1;x<=N;x++) FOR(y,M+1) {
			int lef=N-x+M-y;
			if(x<N) {
				if(x) dp[x+1][y][0]=min(dp[x+1][y][0],dp[x][y][0]+1LL*(A[x]-A[x-1])*lef);
				if(y) dp[x+1][y][0]=min(dp[x+1][y][0],dp[x][y][1]+1LL*(A[x]+B[y-1])*lef);
			}
			if(y<M) {
				if(x) dp[x][y+1][1]=min(dp[x][y+1][1],dp[x][y][0]+1LL*(A[x-1]+B[y])*lef);
				if(y) dp[x][y+1][1]=min(dp[x][y+1][1],dp[x][y][1]+1LL*(B[y]-B[y-1])*lef);
			}
		}
		return min(dp[N][M][0],dp[N][M][1]);
		
    }
};


