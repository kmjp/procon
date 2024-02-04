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
    long long maximumSubarraySum(vector<int>& nums, int k) {
		map<ll,ll> mi;
		ll sum=0;
		ll ret=-(1LL<<60);
		FORR(n,nums) {
			if(mi.count(n+k)) {
				ret=max(ret,sum+n-mi[n+k]);
			}
			if(mi.count(n-k)) {
				ret=max(ret,sum+n-mi[n-k]);
			}
			if(mi.count(n)) {
				mi[n]=min(mi[n],sum);
			}
			else {
				mi[n]=sum;
			}
			sum+=n;
		}
		
		if(ret==-(1LL<<60)) return 0;
       	return ret;
    }
};
