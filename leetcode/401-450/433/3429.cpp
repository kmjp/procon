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


ll from[3][3];
ll to[3][3];

class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
		
		int a,b,c,d,i,j;
		FOR(a,3) FOR(b,3) {
			if(a==b) from[a][b]=1LL<<60;
			else from[a][b]=cost[n/2-1][a]+cost[n/2][b];
		}
		
		for(i=n/2-2;i>=0;i--) {
			int j=n-1-i;
			
			FOR(a,3) FOR(b,3) to[a][b]=1LL<<60;
			FOR(a,3) FOR(b,3) if(from[a][b]<1LL<<60) {
				FOR(c,3) FOR(d,3) {
					if(c!=a&&d!=b&&c!=d) {
						to[c][d]=min(to[c][d],from[a][b]+cost[i][c]+cost[j][d]);
					}
				}
			}
			swap(from,to);
		}
        ll ret=1LL<<60;
        FOR(a,3) FOR(b,3) ret=min(ret,from[a][b]);
        return ret;
    }
};
