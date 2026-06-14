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
    long long maxSum(vector<int>& nums, int k) {
		int N=nums.size();
		ll ret=-1LL<<60;
		auto p=nums;
		sort(ALL(p));
		int x,y;
		
		multiset<int> worst,cand;
		FOR(x,N) {
			worst.clear();
			cand.clear();
			FOR(y,N) {
				if(y<N-k) worst.insert(p[y]);
				else cand.insert(p[y]);
			}
			ll cur=0;
			for(y=x;y<N;y++) {
				if(worst.size()) {
					auto it=worst.find(nums[y]);
					if(it==worst.end()) {
						it=prev(worst.end());
					}
					cand.insert(*it);
					worst.erase(it);
				}
				
				auto it=prev(cand.end());
				cur+=*it;
				cand.erase(it);
				ret=max(ret,cur);
			}
		}
		return ret;
        
    }
};
