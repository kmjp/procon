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

int R[101010],L[101010];

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int N=nums.size();
        int i;
        R[N-1]=1;
        for(i=N-2;i>=0;i--) {
			if(nums[i]<=nums[i+1]) R[i]=R[i+1]+1;
			else R[i]=1;
		}
		L[0]=1;
		for(i=1;i<N;i++) {
			if(nums[i-1]<=nums[i]) L[i]=L[i-1]+1;
			else L[i]=1;
		}
		int ret=1;
		FOR(i,N) {
			if(i+1<N) ret=max(ret,1+R[i+1]);
			if(i) ret=max(ret,1+L[i-1]);
			if(i+1<N&&i&&nums[i-1]<=nums[i+1]) ret=max(ret,1+R[i+1]+L[i-1]);
		}
		return ret;
		
    }
};


