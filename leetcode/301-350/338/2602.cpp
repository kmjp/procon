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
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
		vector<ll> S={0};
		sort(ALL(nums));
		FORR(n,nums) S.push_back(S.back()+n);
		vector<ll> ret;
		FORR(q,queries) {
			int x=lower_bound(ALL(nums),q)-nums.begin();
			ll v=(S.back()-S[x])-1LL*q*(nums.size()-x);
			v+=1LL*q*x-S[x];
			ret.push_back(v);
		}
        return ret;
    }
};