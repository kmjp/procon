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

int par[2525][2525];
int apar[2525][2525];

class Solution {
public:
    int almostPalindromic(string s) {
		int N=s.size();
		int x,y;
		FOR(x,N+1) FOR(y,N+1) par[x][y]=apar[x][y]=0;
		FOR(x,N+1) par[x][x]=par[x][x+1]=apar[x][x+1]=1;
		int ma=1;
		for(int len=2;len<=N;len++) {
			for(x=0;x+len<=N;x++) {
				int y=x+len;
				if(par[x+1][y-1]&&s[x]==s[y-1]) par[x][y]=1;
				if(apar[x+1][y-1]&&s[x]==s[y-1]) apar[x][y]=1;
				if(par[x+1][y]) apar[x][y]=1;
				if(par[x][y-1]) apar[x][y]=1;
				if(apar[x][y]) ma=len;
			}
		}
        return ma;
    }
};


