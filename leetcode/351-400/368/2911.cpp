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

int C[202][202];
int dp[202][202];

class Solution {
public:
    int cost(string s) {
		int N=s.size();
		int mi=1<<20;
		for(int d=1;d<N;d++) if(N%d==0) {
			int c=0;
			int i,j;
			FOR(i,d) {
				string v;
				for(j=i;j<N;j+=d) v+=s[j];
				FOR(j,v.size()/2) c+=v[j]!=v[v.size()-1-j];
			}
			mi=min(mi,c);
		}
		return mi;
	}
    int minimumChanges(string s, int k) {
        int i,x,y;
        int N=s.size();
        FOR(x,N) for(y=x+1;y<=N;y++) C[x][y]=cost(s.substr(x,y-x));
        FOR(x,N+1) FOR(y,N+1) dp[x][y]=1<<20;
        dp[0][0]=0;
        FOR(i,N) {
			FOR(x,N) for(y=x+1;y<=N;y++) chmin(dp[i+1][y],dp[i][x]+C[x][y]);
		}
        return dp[k][N];
        
        
    }
};

