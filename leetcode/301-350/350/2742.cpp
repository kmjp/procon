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



int dp[505];

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int N=cost.size();
        int i,j;
        FOR(i,504) dp[i]=1<<30;
        dp[0]=0;
        FOR(i,N) {
			int c=cost[i],t=time[i];
			for(j=N;j>=0;j--) {
				dp[min(N,j+t+1)]=min(dp[min(N,j+t+1)],dp[j]+c);
			}
		}
		return dp[N];
    }
};
