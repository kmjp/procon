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
ll dp[151];


class Solution {
public:
    int countCoprime(vector<vector<int>>& mat) {
		ZERO(dp);
		int H=mat.size();
		int i,j;
		for(i=150;i>=1;i--) {
			ll pat=1;
			FORR(r,mat) {
				int num=0;
				FORR(c,r) if(c%i==0) num++;
				pat=pat*num%mo;
			}
			dp[i]=pat;
			for(j=i*2;j<=150;j+=i) dp[i]+=mo-dp[j];
			dp[i]%=mo;
		}
        return dp[1];
    }
};

