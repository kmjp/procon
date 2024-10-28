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

ll from[202][202];
ll to[202][202];

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        ZERO(from);
        from[0][0]=1;
        int x,y;
        FORR(v,nums) {
			ZERO(to);
			FOR(x,201) FOR(y,201) if(from[x][y]) {
				to[__gcd(x,v)][y]+=from[x][y];
				to[x][__gcd(y,v)]+=from[x][y];
				to[x][y]+=from[x][y];
			}
			FOR(x,201) FOR(y,201) from[x][y]=to[x][y]%mo;
		}
		ll ret=0;
		for(x=1;x<=200;x++) ret+=from[x][x];
		return ret%mo;
    }
};

