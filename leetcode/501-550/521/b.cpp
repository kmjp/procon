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
    int maxEqualAdjacentPairs(vector<int>& nums) {
		map<int,int> S;
		map<pair<int,int>,int> V;
		
		int i,N=nums.size();
		int ret=0;
		FOR(i,N-1) {
			if(nums[i]==nums[i+1]) {
				S[nums[i]]++;
				ret++;
			}
			else {
				V[{min(nums[i],nums[i+1]),max(nums[i],nums[i+1])}]++;
			}
		}
		
		int ma=0;
		FORR2(a,b,V) ma=max(ma,b);
		return ret+ma;
        
    }
};


