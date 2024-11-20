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
	int can(ll v,vector<int> nums) {
		int i;
		int N=nums.size();
		ll x=1LL<<31;
		ll y=-1LL<<31;
		FOR(i,N-1) {
			if(nums[i]==-1&&nums[i+1]==-1) continue;
			else if(nums[i]==-1) {
				x=min(x,nums[i+1]+v);
				y=max(y,nums[i+1]-v);
			}
			else if(nums[i+1]==-1) {
				x=min(x,nums[i]+v);
				y=max(y,nums[i]-v);
			}
			else {
				if(abs(nums[i+1]-nums[i])>v) return 0;
			}
		}
		
		ll pre=-1LL<<30;
		int n1=0;
		//cout<<v<<" "<<x<<" "<<y<<endl;
		FOR(i,N) {
			//cout<<"#"<<i<<" "<<pre<<" "<<nums[i]<<" "<<n1<<endl;
			if(nums[i]!=-1) {
				int ok=0;
				if(pre<0) {
					ok=1;
				}
				else if(pre>0) {
					if(n1==0) {
						ok=1;
					}
					if(abs(pre-x)<=v&&abs(nums[i]-x)<=v) ok=1;
					if(abs(pre-y)<=v&&abs(nums[i]-y)<=v) ok=1;
					if(n1>=2) {
						if(x+v>=y) ok=1;
					}
					if(ok==0) return 0;
				}
				n1=0;
				pre=nums[i];
			}
			else {
				n1++;
			}
		}
		return 1;
		
	}
    int minDifference(vector<int>& nums) {
		int N=nums.size();
		
		int ret=(1<<30)-1;
		int i;
		for(i=29;i>=0;i--) if(can(ret-(1<<i),nums)) ret-=1<<i;
		return ret;
        
    }
};
