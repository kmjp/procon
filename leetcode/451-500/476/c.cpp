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

ll p10[18],p9[18];

class Solution {
public:
    long long countDistinct(long long n) {
        string S=to_string(n);
        
        p10[0]=p9[0]=1;
        int i;
        FOR(i,16) {
			p10[i+1]=p10[i]*10;
			p9[i+1]=p9[i]*9;
		}
		int d=S.size();
		ll ret=0;
		for(i=1;i<d;i++) ret+=p9[i];
		FOR(i,d) {
			if(S[i]=='0') break;
			else ret+=(S[i]-'1')*p9[d-1-i];
		}
		if(i==d) ret++;
		return ret;
        
        
    }
};
