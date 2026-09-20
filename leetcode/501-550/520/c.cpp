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
    long long maxValue(vector<int>& nums) {
		ll sum=0;
		int i,N=nums.size();
		ll ma[2]={0,-1LL<<60};
		ll cur=0;
		ll ret=0;
		ll tmp=0;
		FOR(i,N) {
			if(i%2==0) cur+=nums[i];
			else cur-=nums[i];
			tmp=max(tmp,ma[(i+1)%2]-cur);
			ma[(i+1)%2]=max(ma[(i+1)%2],cur);
		}
		cout<<tmp<<endl;
		return cur+2*tmp;
        
    }
};
