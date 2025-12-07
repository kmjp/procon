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
    long long minInversionCount(vector<int>& nums, int k) {
		ZERO(bt.bit);
        ll ret=0;
        ll ma=1LL<<60;
        int i,N=nums.size();
        vector<int> Vs;
        FOR(i,nums.size()) Vs.push_back(nums[i]);
        sort(ALL(Vs));
        Vs.erase(unique(ALL(Vs)),Vs.end());
        FOR(i,nums.size()) {
			nums[i]=lower_bound(ALL(Vs),nums[i])-Vs.begin();
			ret+=bt(N)-bt(nums[i]);
			bt.add(nums[i],1);
			if(i>=k) {
				ret-=bt(nums[i-k]-1);
				bt.add(nums[i-k],-1);
			}
			if(i>=k-1) ma=min(ma,ret);
		}
		return ma;
    }
};

