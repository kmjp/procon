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
    long long numOfSubsequences(string s) {
		int NL=0,NT=0;
		FORR(c,s) if(c=='T') NT++;
		ll ret=0;
		ll mac=0;
		ll mal=0;
		ll mat=0;
		FORR(c,s) {
			mac=max(mac,1LL*NL*NT);
			if(c=='L') NL++;
			if(c=='T') NT--;
			if(c=='C') {
				ret+=1LL*NL*NT;
				mal+=NL;
				mat+=NT;
			}
		}
		return ret+max({mac,mal,mat});
        
    }
};


