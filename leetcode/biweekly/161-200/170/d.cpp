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
	ll hoge(ll V) {
		ll p10[18];
		
		if(V<100) return 0;
		int i;
		p10[0]=1;
		FOR(i,17) p10[i+1]=p10[i]*10;
		int a,b,c,d;
		ll ret=0;
		FOR(a,10) FOR(b,10) FOR(c,10) {
			int ok=0;
			if(a<b&&c<b) ok=1;
			if(a>b&&c>b) ok=1;
			if(ok==0) continue;
			FOR(d,13) {
				ll cv=(a*100+b*10+c)*p10[d];
				if(cv>V) continue;
				
				ll pat=V/p10[d+3];
				if(pat*p10[d+3]+cv<=V&&(pat||a)) {
					ret+=min(p10[d],V-(pat*p10[d+3]+cv)+1);
				}
				if(a==0) pat--;
				if(pat>=0) ret+=pat*p10[d];
				
			}
		}
		return ret;
		
	}

    long long totalWaviness(long long num1, long long num2) {
        
        return hoge(num2)-hoge(num1-1);
        
    }
};

