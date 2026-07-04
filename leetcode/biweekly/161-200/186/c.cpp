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


int dp[202020][2];

class Solution {
public:
    int minOperations(string s1, string s2) {
		int N=s1.size();
		int i;
		FOR(i,N+2) dp[i][0]=dp[i][1]=1<<30;
		if(s1[0]=='0') {
			dp[0][0]=0;
			dp[0][1]=1;
		}
		else {
			dp[0][0]=1<<30;
			dp[0][1]=0;
		}
		for(i=1;i<N;i++) {
			if(s2[i-1]=='0') {
				//00->00,01
				if(s1[i]=='0') {
					chmin(dp[i][0],dp[i-1][0]);
					chmin(dp[i][1],dp[i-1][0]+1);
				}
				//01->00,01
				if(s1[i]=='1') {
					chmin(dp[i][0],dp[i-1][0]+2);
					chmin(dp[i][1],dp[i-1][0]);
				}
				//10->00,01
				if(s1[i]=='0') {
					chmin(dp[i][0],dp[i-1][1]+2);
					chmin(dp[i][1],dp[i-1][1]+3);
				}
				//11->00,01
				if(s1[i]=='1') {
					chmin(dp[i][0],dp[i-1][1]+1);
					chmin(dp[i][1],dp[i-1][1]+2);
				}
			}
			else {
				//00->10,11
				if(s1[i]=='0') {
					chmin(dp[i][0],dp[i-1][0]+1);
					chmin(dp[i][1],dp[i-1][0]+2);
				}
				//01->10,11
				if(s1[i]=='1') {
					chmin(dp[i][0],dp[i-1][0]+3);
					chmin(dp[i][1],dp[i-1][0]+1);
				}
				//10->10,11
				if(s1[i]=='0') {
					chmin(dp[i][0],dp[i-1][1]);
					chmin(dp[i][1],dp[i-1][1]+1);
				}
				//11->10,11
				if(s1[i]=='1') {
					chmin(dp[i][0],dp[i-1][1]+2);
					chmin(dp[i][1],dp[i-1][1]);
				}
			}
			
			
			
		}
		int ret=dp[N-1][s2.back()-'0'];
		if(ret>=1<<30) ret=-1;
		return ret;
        
    }
};


