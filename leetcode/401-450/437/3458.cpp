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

int dp[101010];

class Solution {
public:
    bool maxSubstringLength(string s, int k) {
		vector<int> V[26];
		int i;
		int N=s.size();
		FOR(i,N) {
			s[i]-='a';
			V[s[i]].push_back(i);
		}
		FOR(i,N+1) dp[i]=0;
		int ma=0;
		int x,y,z;
		FOR(i,N+1) {
			if(i) dp[i]=max(dp[i],dp[i-1]);
			ma=max(ma,dp[i]);
			FOR(x,26) if(V[x].size()&&V[x][0]==i) {
				FOR(y,26) if(V[y].size()&&V[y].back()>=i) {
					if(i==0&&V[y].back()==N-1) continue;
					int ok=1;
					FOR(z,26) if(V[z].size()) {
						if(V[z][0]<V[x][0]||V[z].back()>V[y].back()) {
							auto it=lower_bound(ALL(V[z]),i);
							if(it!=V[z].end()&&*it<=V[y].back()) ok=0;
						}
					}
					if(ok) dp[V[y].back()+1]=max(dp[V[y].back()+1],dp[i]+1);
				}
			}
			
		}
		
		
		
		return ma>=k;
        
    }
};

