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


int dp[5050];

class Solution {
public:
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        int N=source.size();
        int M=rules.size();
        int i,j,x;
        FOR(i,N) dp[i+1]=1<<30;
        dp[0]=0;
        
        FOR(i,N) if(dp[i]<1<<30) {
			cout<<i<<" "<<dp[i]<<endl;
			if(source[i]==target[i]) {
				dp[i+1]=min(dp[i+1],dp[i]);
			}
			FOR(j,M) if(i+rules[j][0].size()<=N) {
				int c=costs[j];
				FOR(x,rules[j][0].size()) {
					if(rules[j][0][x]=='*') c++;
					if(rules[j][0][x]!='*'&&source[i+x]!=rules[j][0][x]) break;
					if(target[i+x]!=rules[j][1][x]) break;
				}
				if(x==rules[j][0].size()) dp[i+rules[j][0].size()]=min(dp[i+rules[j][0].size()],dp[i]+c);
			}
		}
		if(dp[N]>=1<<30) return -1;
		return dp[N];
        
    }
};
