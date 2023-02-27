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
    int maxNumOfMarkedIndices(vector<int>& nums) {
		sort(ALL(nums));
		int N=nums.size();
		int ma=0;
		int i,j;
		for(i=20;i>=0;i--) {
			int tmp=ma+(1<<i);
			if(2*tmp>N) continue;
			FOR(j,tmp) if(2*nums[j]>nums[N-tmp+j]) break;
			if(j==tmp) ma=tmp;
			
		}
		
		
		
		
		return ma*2;
        
    }
};
