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

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
		sort(ALL(nums));
		ll sum=0;
		ll cur=0;
		ll r2=modpow(2);
		int i;
		FOR(i,nums.size()) {
			ll a=nums[i];
			sum+=modpow(a,3);
			sum+=modpow(a,2)*(cur*modpow(2,i)%mo);
			sum%=mo;
			(cur+=a*modpow(r2,i+1))%=mo;
		}
		return sum;
		
        
    }
};
