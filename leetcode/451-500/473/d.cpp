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
    long long numGoodSubarrays(vector<int>& nums, int k) {
		map<int,int> M;
		ll cur=0;
		ll ret=0;
		map<ll,ll> memo;
		memo[cur%k]=1;
		FORR(a,nums) {
			M[a]++;
			int g=k/__gcd(a,k);
			ret-=M[a]/g;
			if(M[a]%g==0) ret++;
			
			cur+=a;
			ret+=memo[cur%k]++;
		}
        return ret;
    }
};


