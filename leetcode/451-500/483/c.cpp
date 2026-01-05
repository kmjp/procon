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
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        int D[2]={};
        int i;
        FOR(i,s.size()) {
			if(s[i]=='0'&&t[i]=='1') D[0]++;
			if(s[i]=='1'&&t[i]=='0') D[1]++;
		}
		ll a=min(1LL*min(D[0],D[1])*2*flipCost,1LL*min(D[0],D[1])*swapCost);
		ll d=abs(D[0]-D[1]);
		ll e=min(1LL*d/2*(swapCost+crossCost)+d%2*flipCost,1LL*d*flipCost);
		return a+e;
    }
};
