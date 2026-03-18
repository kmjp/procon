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
    int longestArithmetic(vector<int>& nums) {
		int ret=3;
		int N=nums.size();
		int i,j;
		FOR(j,2) {;
			FOR(i,N-1) {
				if(i==0||nums[i]-nums[i-1]!=nums[i+1]-nums[i]) {
					int j=i;
					while(j<N-1&&nums[i+1]-nums[i]==nums[j+1]-nums[j]) j++;
					if(j!=N-1) {
						ret=max(ret,j-i+2);
					}
					if(j<N-2&&(nums[i+1]-nums[i])*2==nums[j+2]-nums[j]) {
						j+=2;
						if(j==N-1||nums[j+1]-nums[j]!=nums[i+1]-nums[i]) {
							ret=max(ret,j-i+1);
							continue;
						}
					}
					while(j<N-1&&nums[i+1]-nums[i]==nums[j+1]-nums[j]) j++;
					ret=max(ret,j-i+1);
				}
			}
			reverse(ALL(nums));
		}
		
		return min(ret,N);
        
    }
};

