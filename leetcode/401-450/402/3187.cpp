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
BIT<int,20> bt;

int N;

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        N=nums.size();
        int i;
        FOR(i,N+2) bt.add(i,-bt(i));
        for(i=1;i<N-1;i++) if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]) bt.add(i,1);
        vector<int> ret;
        FORR(q,queries) {
			if(q[0]==2) {
				for(i=max(1,q[1]-1);i<=min(N-2,q[1]+1);i++) {
					if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]) bt.add(i,-1);
				}
				nums[q[1]]=q[2];
				for(i=max(1,q[1]-1);i<=min(N-2,q[1]+1);i++) {
					if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]) bt.add(i,1);
				}
			}
			else {
				if(q[1]==q[2]) ret.push_back(0);
				else ret.push_back(bt(q[2]-1)-bt(q[1]));
			}
		}
		return ret;
    }
};
