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


bool isprime(ll v) {
	for(ll i=2;i*i<=v;i++) if(v%i==0) return false;
	return (v!=1);
}

class Solution {
public:
    long long sumOfLargestPrimes(string s) {
		set<ll> V;
		
		int x,y,N=s.size();
		FOR(x,N) {
			ll a=0;
			for(y=x;y<N;y++) {
				a=a*10+s[y]-'0';
				if(isprime(a)) V.insert(-a);
			}
		}
		
		ll ret=0;
		int lef=3;
		FORR(a,V) if(lef-->0) ret+=-a;
		return ret;
        
    }
};
