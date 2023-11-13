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



class Solution {
public:
    int distributeCandies(int n, int limit) {
   		ll pat=0;
		int i;
		for(i=0;i<=min(n,limit);i++) {
			ll lef=n-i;
			if(lef<=limit) {
				pat+=lef+1;
			}
			else if(lef<=2*limit) {
				pat+=limit-(lef-limit)+1;
			}
		}
        return pat;
     
    }
};