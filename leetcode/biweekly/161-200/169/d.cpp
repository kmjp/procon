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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,18> bt;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
		int cur=1<<17;
		int N=nums.size();
		
		ll ret=0;
		bt.add(cur,1);
		FORR(a,nums) {
			if(a==target) cur++;
			else cur--;
			ret+=bt(cur-1);
			bt.add(cur,1);
		}
		
		
		for(int i=(1<<17)-N;i<=(1<<17)+N;i++) bt.add(i,-bt(i));
		return ret;
		
        
    }
};

