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
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
		int ret=1010;
		int N=nums1.size();
		int i;
		int cur=0;
		FOR(i,N-1) {
			if(nums1[i]<=nums1[N-1]&&nums2[i]<=nums2[N-1]) {
				continue;
			}
			else if(nums2[i]<=nums1[N-1]&&nums1[i]<=nums2[N-1]) {
				cur++;
			}
			else {
				cur=1010;
			}
		}
        ret=min(cur,ret);
        cur=1;
        swap(nums1[N-1],nums2[N-1]);
		FOR(i,N-1) {
			if(nums1[i]<=nums1[N-1]&&nums2[i]<=nums2[N-1]) {
				continue;
			}
			else if(nums2[i]<=nums1[N-1]&&nums1[i]<=nums2[N-1]) {
				cur++;
			}
			else {
				cur=1010;
			}
		}
		ret=min(cur,ret);
		if(ret>1000) ret=-1;
		return ret;
        
    }
};
