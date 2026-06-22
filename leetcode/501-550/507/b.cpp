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
    int countValidSubarrays(vector<int>& nums, int x) {
		int ret=0;
		int i,j;
		int N=nums.size();
		FOR(i,N) {
			ll sum=0;
			for(j=i;j<N;j++) {
				sum+=nums[j];
				ll c=sum;
				while(c>=10) c/=10;
				if(c==x&&sum%10==x) ret++;
			}
		}
		return ret;
        
    }
};
