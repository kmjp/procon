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
    long long splitArray(vector<int>& nums) {
		ll ret=1LL<<60;
		int i,N=nums.size();
		vector<int> cand;
		FOR(i,N-1) if(i) {
			if(nums[i-1]<=nums[i]&&nums[i+1]<=nums[i]) {
				cand.push_back(i-1);
				cand.push_back(i);
			}
		}
		cand.push_back(0);
		cand.push_back(N-2);
		
		if(cand.size()>=10) return -1;
		FORR(c,cand) {
			cout<<c<<endl;
			ll a=nums[c],b=nums[c+1];
			for(i=c-1;i>=0;i--) {
				if(nums[i]>=nums[i+1]) {
					a=-1;
					break;
				}
				a+=nums[i];
			}
			for(i=c+2;i<N;i++) {
				if(nums[i]>=nums[i-1]) {
					b=-1;
					break;
				}
				b+=nums[i];
			}
			if(a>=0&&b>=0) ret=min(ret,abs(a-b));
		}
		if(ret==1LL<<60) ret=-1;
		return ret;
        
    }
};

