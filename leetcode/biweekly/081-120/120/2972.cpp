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

int ok[101010];

class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int N=nums.size();
        int i;
        vector<int> C;
        C.push_back(1<<30);
        for(i=N-1;i>=0;i--) {
			if(nums[i]>=C.back()) break;
			C.push_back(nums[i]);
		}
		if(i==-1) return 1LL*N*(N+1)/2;
		reverse(ALL(C));
		ll ret=C.size();
		cout<<ret<<endl;
		int pre=0;
		FOR(i,N) {
			if(nums[i]<=pre) break;
			pre=nums[i];
			ret+=C.end()-lower_bound(ALL(C),nums[i]+1);
		}
		return ret;
		
        
    }
};
