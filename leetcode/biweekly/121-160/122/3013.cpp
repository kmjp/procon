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
    long long minimumCost(vector<int>& nums, int k, int dist) {
		ll ret=1LL<<60;
		set<pair<int,int>> A;
		set<pair<int,int>> B;
		int i,N=nums.size();
		ll sum=0;
		FOR(i,k-1) {
			sum+=nums[i];
			if(i) A.insert({nums[i],i});
		}
		for(i=k-1;i<N;i++) {
			int x=i-dist-1;
			if(x>0) {
				if(A.count({nums[x],x})) {
					A.erase({nums[x],x});
					sum-=nums[x];
					if(B.size()) {
						A.insert(*B.begin());
						sum+=B.begin()->first;
						B.erase(B.begin());
					}
				}
				else if(B.count({nums[x],x})) {
					B.erase({nums[x],x});
				}
			}
			assert(A.size()==k-2);
			ret=min(ret,sum+nums[i]);
			sum+=nums[i];
			A.insert({nums[i],i});
			auto it=prev(A.end());
			B.insert(*it);
			sum-=it->first;
			A.erase(it);
		}
		return ret;
        
    }
};
