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
    long long findMaximumNumber(long long k, int x) {
		ll ret=0;
		int i;
		for(i=50;i>=0;i--) {
			ll tmp=ret+(1LL<<i);
			ll sum=0;
			
			for(ll a=(1LL<<(x-1));sum<=k&&a<=tmp;a<<=x) {
				if(tmp&a) {
					sum+=(tmp/a-1)/2*a+(1+tmp%a);
				}
				else {
					sum+=(tmp/a)/2*a;
				}
			}
			if(sum<=k) ret=tmp;
		}
		return ret;
        
    }
};
