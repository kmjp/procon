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


ll S[2][202020];

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int i,N=prices.size();
        ll sum=0;
        FOR(i,N) {
			S[0][i+1]=S[0][i];
			S[1][i+1]=S[1][i];
			S[0][i+1]+=prices[i]*(0-strategy[i]);
			S[1][i+1]+=prices[i]*(1-strategy[i]);
			sum+=prices[i]*strategy[i];
		}
		ll ret=sum;
		k/=2;
		FOR(i,N) if(i+2*k<=N) {
			ll dif=S[0][i+k]-S[0][i]+S[1][i+2*k]-S[1][i+k];
			ret=max(ret,sum+dif);
		}
		return ret;
		
    }
};


