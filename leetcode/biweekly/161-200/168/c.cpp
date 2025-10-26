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
	ll hoge(ll a, ll x,ll y) {
		if(a<=y&&y<=x) return x-a;
		if(a>=y&&y>=x) return a-x;
		return min({abs(a-x)+abs(x-y),abs(a-y)+abs(x-y),abs(a-y)+abs(a-x)});
		
	}
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
		int N=nums1.size();
		ll ret=0;
		int i;
		FOR(i,N) ret+=abs(nums1[i]-nums2[i]);
		ll mi=1LL<<60;
		FOR(i,N) {
			mi=min(mi,ret-abs(nums1[i]-nums2[i])+hoge(nums1[i],nums2[i],nums2.back())+1);
		}
		return mi;
        
    }
};
