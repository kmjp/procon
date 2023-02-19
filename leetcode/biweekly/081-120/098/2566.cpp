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
    int minMaxDifference(int num) {
		set<ll> S;
		int x,y;
		FOR(x,10) FOR(y,10) {
			ll a=num;
			ll b=0;
			ll p10=1;
			while(a) {
				if(a%10==x) b+=y*p10;
				else b+=(a%10)*p10;
				a/=10;
				p10*=10;
			}
			S.insert(b);
		}
        return *S.rbegin()-*S.begin();
    }
};
