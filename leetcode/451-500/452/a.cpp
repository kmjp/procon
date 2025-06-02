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
    bool checkEqualPartitions(vector<int>& nums, long long target) {
		int mask;
		int N=nums.size();
		int i;
		FOR(mask,1<<N) {
			ll A=target;
			ll B=target;
			int ng=0;
			FOR(i,N) {
				if(mask&(1<<i)) {
					if(A%nums[i]) ng=1;
					A/=nums[i];
				}
				else {
					if(B%nums[i]) ng=1;
					B/=nums[i];
				}
			}
			if(A==1&&B==1&&ng==0) return 1;
		}
        return 0;
    }
};
