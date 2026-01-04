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

ll from[777];
ll to[777];

class Solution {
public:
    int numberOfRoutes(vector<string>& grid, int d) {
		
		int d1=d,d2=0;
		while((d2+1)*(d2+1)+1+1<=d*d) d2++;
		
		
		//1—ñ–Ú
		int H=grid.size(),W=grid[0].size();
		int x,y;
		int f=1;
		FOR(x,W) from[x+1]=1;
		FORR(S,grid) {
			if(f==1) {
				FOR(x,W) {
					if(S[x]=='#') to[x+1]=0;
					else to[x+1]=1;
					(to[x+1]+=to[x])%=mo;
				}
				f=0;
			}
			else {
				FOR(x,W) {
					(from[x+1]+=from[x])%=mo;
				}
				FOR(x,W) {
					int R=min(W-1,x+d2);
					int L=max(0,x-d2);
					if(S[x]=='#') to[x+1]=0;
					else to[x+1]=(from[R+1]-from[L]+mo)%mo;
					(to[x+1]+=to[x])%=mo;
				}
			}
			FOR(x,W) {
				int R=min(W-1,x+d);
				int L=max(0,x-d);
				if(S[x]=='#') from[x+1]=0;
				else from[x+1]=(to[R+1]-to[L]+mo)%mo;
			}
		}
		ll ret=0;
		FOR(x,W) ret+=from[x+1];
		return ret%mo;
		
		
        
    }
};
