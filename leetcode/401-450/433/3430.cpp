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
    long long minMaxSubarraySum(vector<int>& nums, int k) {
        deque<pair<ll,ll>> mi,ma;
        int N=nums.size();
        ll ret=0;
        ll cur=0;
        for(int i=N-1;i>=0;i--) {
			if(i+k<N) {
				cur-=ma.back().first;
				cur-=mi.back().first;
				if(ma.back().second==i+k) ma.pop_back();
				if(mi.back().second==i+k) mi.pop_back();
			}
			ll v=nums[i];
			while(ma.size()&&ma[0].first<=v) {
				if(ma.size()==1) cur-=ma[0].first*(min(i+k,N)-ma[0].second);
				else cur-=ma[0].first*(ma[1].second-ma[0].second);
				ma.pop_front();
			}
			while(mi.size()&&mi[0].first>=v) {
				if(mi.size()==1) cur-=mi[0].first*(min(i+k,N)-mi[0].second);
				else cur-=mi[0].first*(mi[1].second-mi[0].second);
				mi.pop_front();
			}
			if(ma.size()) cur+=v*(ma[0].second-i);
			else cur+=v*(min(i+k,N)-i);
			if(mi.size()) cur+=v*(mi[0].second-i);
			else cur+=v*(min(i+k,N)-i);
			ma.push_front({v,i});
			mi.push_front({v,i});
			ret+=cur;
		}
		return ret;
    }
};

