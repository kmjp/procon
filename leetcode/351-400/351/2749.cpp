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
    int makeTheIntegerZero(int num1, int num2) {
		int i;
		for(i=1;i<=60;i++) {
			ll lef=num1-1LL*i*num2;
			if(lef<0) continue;
			int mi=__builtin_popcountll(lef);
			ll ma=lef;
			if(mi<=i&&i<=ma) return i;
		}
		return -1;
        
    }
};


