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
    long long countSubarrays(vector<int>& nums, long long k) {
		ll ret=0;
		int N=nums.size();
		ll sum=0;
		for(int L=0,R=0;L<N;L++) {
			while(R<N&&(sum+nums[R])*(R+1-L)<k) {
				sum+=nums[R];
				R++;
			}
			ret+=R-L;
			if(R==L) {
				R=L+1;
			}
			else {
				sum-=nums[L];
			}
		}
		return ret;
        
    }
};
