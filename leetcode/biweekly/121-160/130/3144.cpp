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

int dp[1010];

class Solution {
public:
    int minimumSubstringsInPartition(string s) {
		int N=s.size();
		int x,y;
		FOR(x,1010) dp[x]=1<<20;
		dp[0]=0;
		FOR(x,N) {
			int C[256]={};
			map<int,int> M;
			for(y=x;y<N;y++) {
				if(C[s[y]]) {
					M[C[s[y]]]--;
					if(M[C[s[y]]]==0) M.erase(C[s[y]]);
				}
				C[s[y]]++;
				M[C[s[y]]]++;
				if(M.size()==1) dp[y+1]=min(dp[y+1],dp[x]+1);
			}
		}
        return dp[N];
    }
};
