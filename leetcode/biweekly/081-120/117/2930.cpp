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
ll from[3][2][2];
ll to[3][2][2];

class Solution {
public:
    int stringCount(int n) {
		ZERO(from);
		from[0][0][0]=1;
		while(n--) {
			int a,b,c;
			ZERO(to);
			FOR(a,3) FOR(b,2) FOR(c,2) {
				(to[min(a+1,2)][b][c]+=from[a][b][c])%=mo;
				(to[a][min(b+1,1)][c]+=from[a][b][c])%=mo;
				(to[a][b][min(c+1,1)]+=from[a][b][c])%=mo;
				(to[a][b][c]+=from[a][b][c]*23)%=mo;
			}
			swap(from,to);
		}
		
		return from[2][1][1];
        
    }
};
