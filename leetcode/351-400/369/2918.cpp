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
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
		ll s1=0,s2=0,a1=0,a2=0;
		FORR(n,nums1) {
			if(n>0) s1+=n;
			else a1++,s1++;
		}
		FORR(n,nums2) {
			if(n>0) s2+=n;
			else a2++,s2++;
		}
		if(s1==s2) return s1;
		if(s1>s2&&a2) return s1;
		if(s1<s2&&a1) return s2;
		return -1;
    }
};
