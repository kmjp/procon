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


ll F[2],T[2];

class Solution {
public:
    long long minCost(vector<int>& nums) {
        F[0]=nums[0]+nums.back();
        F[1]=1LL<<60;
        nums.pop_back();
        reverse(ALL(nums));
        nums.pop_back();
        FORR(a,nums) {
			T[0]=min(F[0],F[1]+a);
			T[1]=min(F[1],F[0]+a);
			swap(F,T);
		}
		return F[0];
        
    }
};


