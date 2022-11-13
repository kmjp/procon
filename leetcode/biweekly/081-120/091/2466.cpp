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

const ll mo=1000000007;
ll dp[201010];
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
		ZERO(dp);
		dp[0]=1;
		int i;
		ll sum=0;
		FOR(i,100001) {
			(dp[i+zero]+=dp[i])%=mo;
			(dp[i+one]+=dp[i])%=mo;
			if(i>=low&&i<=high) sum+=dp[i];
		}
        return sum%mo;
    }
};
