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
		int N=nums.size();
		vector<int> L(N),R(N);
		int pre=1<<29;
		int i;
		FOR(i,N) {
			L[i]=pre;
			pre=min(pre,nums[i]);
		}
		pre=1<<29;
		int ret=1<<30;
		for(i=N-1;i>=0;i--) {
			R[i]=pre;
			pre=min(pre,nums[i]);
			if(L[i]<nums[i]&&R[i]<nums[i]) ret=min(ret,L[i]+nums[i]+R[i]);
		}
		
		if(ret>=1<<29) ret=-1;
		return ret;
        
    }
};
