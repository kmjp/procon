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
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
		ll sum=0;
		set<pair<int,int>> S;
		int i;
		FOR(i,nums.size()) {
			sum+=nums[i];
			S.insert({nums[i],i});
		}
		vector<ll> ret;
		FORR(q,queries) {
			if(S.count({nums[q[0]],q[0]})) {
				S.erase({nums[q[0]],q[0]});
				sum-=nums[q[0]];
			}
			while(S.size()&&q[1]) {
				q[1]--;
				sum-=S.begin()->first;
				S.erase(S.begin());
			}
			ret.push_back(sum);
		}
		return ret;
        
    }
};
