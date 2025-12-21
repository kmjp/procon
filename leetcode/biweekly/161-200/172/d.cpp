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
    long long lastInteger(long long n) {
		ll L=1,R=n,step=1;
		int i;
		FOR(i,60) {
			if(L==R) break;
			ll a=1LL<<i;
			if(i%2==0) {
				R=L+(R-L)/(2*a)*2*a;
			}
			else {
				L=R-(R-L)/(2*a)*2*a;
			}
			
		}
		return L;
        
    }
};
