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
    bool checkArray(vector<int>& nums, int k) {
		int N=nums.size();
		vector<ll> D(N+1);
		int i;
		FOR(i,N) {
			if(i) D[i]+=D[i-1];
			nums[i]-=D[i];
			if(nums[i]<0) return 0;
			if(nums[i]>0) {
				if(i+k>N) return 0;
				D[i]+=nums[i];
				D[i+k]-=nums[i];
			}
		}
		
		return 1;
        
    }
};
