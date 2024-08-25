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
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
		vector<ll> V;
		set<pair<ll,int>> S;
		int i,j;
		FOR(i,nums.size()) {
			V.push_back(nums[i]);
			S.insert({nums[i],i});
		}
		
		if(multiplier==1) return nums;
		
		while(k&&S.rbegin()->first/multiplier>=S.begin()->first) {
			k--;
			int x=S.begin()->second;
			S.erase(S.begin());
			V[x]*=multiplier;
			S.insert({V[x],x});
		}
		
		ll a=modpow(multiplier,k/V.size());
		
		FOR(i,V.size()) {
			V[i]=V[i]%mo*a%mo;
		}
		
		FOR(i,k%V.size()) {
			int x=S.begin()->second;
			S.erase(S.begin());
			V[x]=V[x]*multiplier%mo;
		}
		
		FOR(i,V.size()) nums[i]=V[i]%mo;
		
        return nums;
    }
};

