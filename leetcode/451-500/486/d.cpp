#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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


ll dp[55][55];

class Solution {
public:
    long long nthSmallest(long long n, int k) {
		int a,b;
		FOR(a,52) FOR(b,a+1) {
			if(b==0||b==a) dp[a][b]=1;
			else dp[a][b]=dp[a-1][b-1]+dp[a-1][b];
		}
        ll ret=0;
        while(k) {
	        for(a=1;a<=60;a++) {
				if(dp[a][k]>=n) {
					ret+=1LL<<(a-1);
					cout<<"!"<<a<<" "<<n<<" "<<k<<" "<<dp[a][k]<<endl;
					n-=dp[a-1][k];
					k--;
					break;
				}
			}
		}
		return ret;
    }
};

