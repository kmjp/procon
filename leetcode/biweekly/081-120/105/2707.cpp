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

int dp[55];

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
		int N=s.size();
		int i;
		FOR(i,N+1) dp[i]=1<<20;
		dp[0]=0;
		FOR(i,N) {
			dp[i+1]=min(dp[i+1],dp[i]+1);
			FORR(w,dictionary) if(i+w.size()<=s.size()&&s.substr(i,w.size())==w) dp[i+w.size()]=min(dp[i+w.size()],dp[i]);
		}
		
		return dp[N];
		
        
    }
};
