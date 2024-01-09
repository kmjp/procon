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

ll p[20];
ll dp[18][2];
ll V,TL,SL,S;
class Solution {
public:
	ll hoge(int d,int le) {
		if(d<0) return 1;
		if(dp[d][le]>=0) return dp[d][le];
		ll ret=0;
		
		int v=V/p[d]%10;
		int i;
		FOR(i,TL+1) {
			if(le==0&&i>v) continue;
			if(d<SL&&i!=S/p[d]%10) continue;
			ret+=hoge(d-1,le|(i<v));
		}
		return dp[d][le]=ret;
	}
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        int i;
        p[0]=1;
        FOR(i,17) p[i+1]=p[i]*10;
        SL=s.size();
        S=atoll(s.c_str());
        TL=limit;

        MINUS(dp);
        V=finish;
        ll ret=hoge(17,0);
        MINUS(dp);
        V=start-1;
	    ret-=hoge(17,0);
        return ret;
        
    }
};
