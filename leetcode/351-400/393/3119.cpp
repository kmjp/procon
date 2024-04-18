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
    long long findKthSmallest(vector<int>& coins, int k) {
		ll ret=(1LL<<40)-1;
		int i;
		int mask,N=coins.size();
		int x,y;
		FOR(x,N) FOR(y,N) if(x!=y&&coins[x]!=-1&&coins[y]!=-1&&coins[y]%coins[x]==0) coins[y]=-1;
		vector<int> C;
		FORR(c,coins) if(c>0) C.push_back(c);
		
		N=C.size();
		
		for(i=39;i>=0;i--) {
			ll num=0;
			
			FOR(mask,1<<N) if(mask) {
				ll lcm=1;
				int par=0;
				FOR(x,N) if(mask&(1<<x)) {
					lcm=min(1LL<<40, lcm*C[x]/__gcd(lcm,(ll)C[x]));
					par^=1;
				}
				if(par==1) num+=(ret-(1LL<<i))/lcm;
				else num-=(ret-(1LL<<i))/lcm;
			}
			if(num>=k) ret-=(1LL<<i);
			
		}
		return ret;
        
    }
};
