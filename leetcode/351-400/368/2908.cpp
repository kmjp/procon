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
    int minimumSum(vector<int>& nums) {
		int mi=1<<30;
		
		int a,b,c;
		FOR(c,nums.size()) FOR(b,c) FOR(a,b) if(nums[a]<nums[b]&&nums[c]<nums[b]) mi=min(mi,nums[a]+nums[b]+nums[c]);
		
		if(mi==1<<30) mi=-1;
		return mi;
        
    }
};
