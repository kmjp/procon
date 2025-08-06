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
    bool isTrionic(vector<int>& nums) {
		int N=nums.size();
		int p,q,i;
		for(p=1;p<N-1;p++) for(q=p+1;q<N-1;q++) {
			int ok=1;
			FOR(i,p) if(nums[i]>=nums[i+1]) ok=0;
			for(i=p;i<q;i++) if(nums[i]<=nums[i+1]) ok=0;
			for(i=q;i<N-1;i++) if(nums[i]>=nums[i+1]) ok=0;
			if(ok) return 1;
		}
		return 0;
        
    }
};
