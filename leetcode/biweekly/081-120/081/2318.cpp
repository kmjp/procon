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

ll from[7][7];
ll to[7][7];
int ok[7][7];
class Solution {
public:
    int distinctSequences(int n) {
		int i,j,k;
		for(i=1;i<=6;i++) {
			ok[0][i]=1;
			for(j=1;j<=6;j++) ok[i][j]=__gcd(i,j)==1;
		}
		ZERO(from);
		from[0][0]=1;
		while(n--) {
			ZERO(to);
			FOR(i,7) FOR(j,7) for(k=1;k<=6;k++) {
				if(k!=i&&k!=j&&ok[j][k]) {
					(to[j][k]+=from[i][j])%=mo;
				}
			}
			
			swap(from,to);
		}
		ll ret=0;
		FOR(i,7) FOR(j,7) ret+=from[i][j];
		return ret%mo;
        
    }
};
