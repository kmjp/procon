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
    long long minimumTime(vector<int>& d, vector<int>& r) {
        ll L=0;
        ll R=1LL<<60;
        while(R-L>=2) {
			ll M=(L+R)/2;
			ll D1=M-M/r[0];
			ll D2=M-M/r[1];
			ll D=M-M/r[0]-M/r[1]+M/(r[0]*r[1]/__gcd(r[0],r[1]));
			
			if(D1>=d[0]&&D2>=d[1]&&D1+D2-D>=d[0]+d[1]) {
				R=M;
			}
			else {
				L=M;
			}
			
		}
		return R;
    }
};

