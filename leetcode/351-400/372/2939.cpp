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


class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        if(a<b) swap(a,b);
        int step=0;
        int i;
        for(i=49;i>=n;i--) {
				if((a&(1LL<<i))!=(b&(1LL<<i))) step=1;
		}
        
        for(i=n-1;i>=0;i--) {
			if((a&(1LL<<i))==(b&(1LL<<i))) {
				a|=1LL<<i;
				b|=1LL<<i;
			}
			else {
				if((a&(1LL<<i))) a^=1LL<<i;
				if((b&(1LL<<i))) b^=1LL<<i;
				if(step==0) {
					a^=1LL<<i;
					step=1;
				}
				else {
					b^=1LL<<i;
				}
				
			}
		}
		cout<<a<<" "<<b<<endl;
        return a%mo*(b%mo)%mo;
        
    }
};
