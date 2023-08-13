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

const int prime_max = 1000000;
vector<int> prime;
int NP,divp[prime_max];
const ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}



class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
		vector<pair<int,int>> V;
		int i;
		set<int> C={-1,(int)nums.size()};
		FOR(i,nums.size()) {
			int num=0;
			int x=nums[i];
			for(int j=2;j*j<=x;j++) if(x%j==0) {
				num++;
				while(x%j==0) x/=j;
			}
			if(x>1) num++;
			V.push_back({num,-i});
		}
		sort(ALL(V));
		reverse(ALL(V));
		vector<pair<int,ll>> cand;
		FORR(a,V) {
			int x=-a.second;
			auto it=C.insert(x).first;
			int R=*next(it);
			int L=*prev(it);
			cand.push_back({nums[x],1LL*(R-x)*(x-L)});
		}
		sort(ALL(cand));
		reverse(ALL(cand));
		ll ret=1;
		FORR(c,cand) {
			c.second=min(c.second,(ll)k);
			k-=c.second;
			ret=ret*modpow(c.first,c.second)%mo;
		}
		
		return ret;
        
    }
};
