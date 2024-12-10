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
    long long maxSubarraySum(vector<int>& nums, int k) {
		ll sum=0;
		ll ret=-1LL<<50;
		map<ll,ll> M;
		M[0]=0;
		int i;
		FOR(i,nums.size()) {
			sum+=nums[i];
			int id=(i+1)%k;
			if(M.count(id)) {
				ret=max(ret,sum-M[id]);
				M[id]=min(M[id],sum);
			}
			else M[id]=sum;
		}
		return ret;
        
    }
};

