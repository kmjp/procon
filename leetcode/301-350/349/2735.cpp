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
    long long minCost(vector<int>& nums, int x) {
        ll mi=1LL<<60;
        int i,j,N=nums.size();
        reverse(ALL(nums));
        FOR(i,N) {
			int m=1<<30;
			ll sum=1LL*i*x;
			FOR(j,N) sum+=nums[j];
			mi=min(mi,sum);
			vector<int> A=nums;
			FOR(j,N) nums[j]=min(nums[j],A[(j+N-1)%N]);
			
		}
        return mi;
    }
};
