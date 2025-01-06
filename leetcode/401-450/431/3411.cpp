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
    int maxLength(vector<int>& nums) {
		int ret=0;
		int x,y,N=nums.size();
		FOR(x,N) {
			ll p=nums[x];
			ll l=p;
			ll g=p;
			if(p==l*g) ret=max(ret,1);
			for(y=x+1;y<N;y++) if(p<1000000) {
				p*=nums[y];
				l=l*nums[y]/__gcd(l,(ll)nums[y]);
				g=__gcd(g,(ll)nums[y]);
				if(p==l*g) ret=max(ret,y-x+1);
			}
		}
		return ret;
        
    }
};

