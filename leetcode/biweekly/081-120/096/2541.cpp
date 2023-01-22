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
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
		ll add=0,sub=0;
		int i;
		FOR(i,nums1.size()) {
			ll a=nums1[i]-nums2[i];
			if(k==0&&a) return -1;
			if(k==0) continue;
			if(a%k) return -1;
			a/=k;
			if(a>0) add+=a;
			else sub+=-a;
		}
        if(add==sub) return add;
        return -1;
    }
};
