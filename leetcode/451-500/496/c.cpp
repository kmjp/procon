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


ll L[101010],R[101010];

class Solution {
public:
    long long minIncrease(vector<int>& nums) {
		int N=nums.size();
		ll ret=0;
		int i;
		FOR(i,N+5) L[i]=R[i]=0;
		if(N%2) {
			for(i=1;i<N;i+=2) {
				if(nums[i]<=nums[i+1]||nums[i]<=nums[i-1]) {
					ret+=max(nums[i+1],nums[i-1])-nums[i]+1;
				}
			}
		}
		else {
			for(i=1;i<N-1;i++) {
				ll v=0;
				if(nums[i]<=nums[i+1]||nums[i]<=nums[i-1]) v=max(nums[i+1],nums[i-1])-nums[i]+1;
				L[i]=v;
				if(i!=1) L[i]+=L[i-2];
			}
			for(i=N-2;i>=1;i--) {
				ll v=0;
				if(nums[i]<=nums[i+1]||nums[i]<=nums[i-1]) v=max(nums[i+1],nums[i-1])-nums[i]+1;
				R[i]=v;
				R[i]+=R[i+2];
			}
			ret=min(R[2],L[N-2]);
			for(i=1;i<N-1;i+=2) {
				ret=min(ret,L[i]+R[i+3]);
			}
			
		}
		return ret;
        
    }
};


