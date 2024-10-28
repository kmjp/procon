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
    int lengthAfterTransformations(string s, int t) {
		ll F[26]={};
		FORR(c,s) F[c-'a']++;
		int i,j;
		FOR(i,t) {
			ll a=F[25];
			for(j=25;j>0;j--) F[j]=F[j-1];
			F[0]=a;
			(F[1]+=a)%=mo;
		}
        ll ret=0;
        FOR(i,26) ret+=F[i];
        return ret%mo;
    }
};

