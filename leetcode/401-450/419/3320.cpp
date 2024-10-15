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


ll from[2020][4],to[2020][4];
const ll mo=1000000007;

class Solution {
public:
    int countWinningSequences(string s) {
        ZERO(from);
        from[1010][3]=1;
        int i,x,y;
        FORR(c,s) {
			if(c=='F') c=0;
			if(c=='W') c=1;
			if(c=='E') c=2;
			ZERO(to);
			for(i=1;i<=2000;i++) FOR(x,4) FOR(y,3) if(x!=y) {
				if(c==y) (to[i+1][y]+=from[i][x])%=mo;
				if(c==(y+1)%3) (to[i][y]+=from[i][x])%=mo;
				if(c==(y+2)%3) (to[i-1][y]+=from[i][x])%=mo;
			}
			swap(from,to);
		}
		ll ret=0;
		for(int i=1011;i<=2015;i++) FOR(x,3) ret+=from[i][x];
		return ret%mo;
    }
};


