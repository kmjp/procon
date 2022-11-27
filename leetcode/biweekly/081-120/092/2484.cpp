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

ll dp[6][10][10];
const ll mo=1000000007;

class Solution {
public:
    int countPalindromes(string s) {
		ZERO(dp);
		
		int i,a,b;
		FOR(a,10) FOR(b,10) dp[0][a][b]=1;
		FORR(c,s) {
			c-='0';
			for(i=4;i>=0;i--) {
				FOR(a,10) FOR(b,10) {
					if((i==0||i==4)&&a==c) (dp[i+1][a][b]+=dp[i][a][b])%=mo;
					if((i==1||i==3)&&b==c) (dp[i+1][a][b]+=dp[i][a][b])%=mo;
					if(i==2) (dp[i+1][a][b]+=dp[i][a][b])%=mo;
				}
			}
		}
		ll ret=0;
		FOR(a,10) FOR(b,10) ret+=dp[5][a][b];
		return ret%mo;
        
    }
};
