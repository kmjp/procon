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
    long long maxScore(vector<int>& nums) {
        ll a=1;
        ll b=0;
        FORR(v,nums) {
			a=a*v/__gcd((ll)v,a);
			b=__gcd((ll)v,b);
		}
		ll ret=a*b;
		int i,j;
		FOR(i,nums.size()) {
	        ll a=1;
	        ll b=0;
	        FOR(j,nums.size()) if(i!=j) {
				a=a*nums[j]/__gcd((ll)nums[j],a);
				b=__gcd((ll)nums[j],b);
			}
			ret=max(ret,a*b);
		}
		return ret;
    }
};
