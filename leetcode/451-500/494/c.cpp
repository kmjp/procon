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

int from[1<<14],to[1<<14];

class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
		int mask;
		FOR(mask,1<<14) from[mask]=-1<<30;
		from[0]=0;
		FORR(a,nums) {
			FOR(mask,1<<14) to[mask]=from[mask];
			FOR(mask,1<<14) to[mask^a]=max(to[mask^a],from[mask]+1);
			swap(from,to);
		}
		
		int ret=from[target];
		if(ret<0) return -1;
		return nums.size()-ret;
        
    }
};


