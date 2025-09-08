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

vector<ll> cand;
class Solution {
public:
    int countBinaryPalindromes(long long n) {
		int i;
		
		ll ret=1;
		if(n>=1) ret=2;
		for(int d=2;d<=50;d++) {
			ll L=1LL+(1LL<<(d-1));
			ll R=(1LL<<d)-1;
			if(n>=R) {
				ret+=1LL<<((d-1)/2);
			}
			else if(n>=L) {
				for(int x=d-2,y=1;x>=y;x--,y++) {
					if((L|(1LL<<x)|(1LL<<y))<=n) {
						L|=(1LL<<x)|(1LL<<y);
					}
				}
				if(d%2==0) {
					ret+=((L^(1LL<<(d-1)))>>(d/2))+1;
				}
				else {
					ret+=((L^(1LL<<(d-1)))>>(d/2))+1;
				}
			}
			
		}
		return ret;
    }
};


