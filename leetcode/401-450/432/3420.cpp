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
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
		deque<array<ll,3>> D;
		ll sum=0;
		ll ret=0;
		int i;
		int N=nums.size();
		for(i=N-1;i>=0;i--) {
			ll cur=nums[i];
			ll a=i;
			ll b=i;
			while(D.size()&&D[0][0]<=cur) {
				sum+=1LL*(cur-D[0][0])*(D[0][2]-D[0][1]+1);
				b=D[0][2];
				D.pop_front();
			}
			D.push_front({cur,a,b});
			while(sum>k) {
				sum-=D.back()[0]-nums[D.back()[2]];
				D.back()[2]--;
				if(D.back()[2]<D.back()[1]) D.pop_back();
			}
			ret+=D.back()[2]-i+1;
		}
		return ret;
        
    }
};


