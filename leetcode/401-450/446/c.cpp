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
    vector<long long> resultArray(vector<int>& nums, int k) {
		ll from[5]={};
		ll to[5]={};
		vector<ll> R(k);
		ll i;
		FORR(a,nums) {
			ZERO(to);
			FOR(i,k) {
				to[i*a%k]+=from[i];
			}
			to[a%k]++;
			FOR(i,k) {
				R[i]+=to[i];
				from[i]=to[i];
			}
		}
		return R;
        
    }
};

