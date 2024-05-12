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
	vector<ll> num(ll v) {
		int i;
		v++;
		vector<ll> V;
		FOR(i,50) {
			ll a=1LL<<i;
			ll sum=v/(2*a)*a;
			ll vv=v%(2*a);
			if(vv>a) sum+=vv-a;
			
			V.push_back(sum);
		}
		return V;
	}
	
	
	vector<ll> hoge(ll v) {
		vector<ll> R(50);
		if(v<=0) return R;
		ll cur=0;
		int i;
		for(i=50;i>=0;i--) {
			vector<ll> V=num(cur+(1LL<<i));
			ll s=0;
			FORR(a,V) s+=a;
			if(s<=v) cur+=1LL<<i;
		}
		vector<ll> V=num(cur);
		ll s=0;
		FORR(a,V) s+=a;
		cur++;
		FOR(i,50) if(cur&(1LL<<i)&&s<v) {
			V[i]++;
			s++;
		}
		return V;
	}
	ll modpow(ll a, ll n,ll mo) {

		ll r=1;a%=mo;
		while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
		return r;
	}

    vector<int> findProductsOfElements(vector<vector<long long>>& queries) {
		vector<int> ret;
		FORR(e,queries) {
			auto A=hoge(e[1]+1);
			auto B=hoge(e[0]);
			int i;
			ll sum=0;
			FOR(i,50) {
				sum+=(A[i]-B[i])*i;
			}
			ret.push_back(modpow(2,sum,e[2])%e[2]);
		}
        return ret;
    }
};
