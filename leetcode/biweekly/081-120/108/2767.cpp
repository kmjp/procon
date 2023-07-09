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

int dp[20];

class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        int i,N=s.size();
        FOR(i,N+2) dp[i]=1<<20;
        dp[0]=0;
        int x,y;
        FOR(x,N) if(dp[x]<1<<20&&s[x]=='1') {
			int v=0;
			for(y=x;y<N;y++) {
				v=v*2+s[y]-'0';
				int w=v;
				while(w>1) {
					if(w%5) break;
					w/=5;
				}
				if(w==1) dp[y+1]=min(dp[y+1],dp[x]+1);
			}
			cout<<x<<" "<<dp[x+1]<<endl;
		}
        if(dp[N]>=1<<20) return -1;
        return dp[N];
    }
};
