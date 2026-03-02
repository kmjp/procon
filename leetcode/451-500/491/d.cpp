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
    long long countSubarrays(vector<int>& nums, int k, int m) {
        map<int,int> cnt1,cnt2;
        int ok=0;
        ll ret=0;
        int N=nums.size();
        for(int L=0,R1=0,R2=0;L<N;L++) {
			while(R2<N&&cnt2.size()<=k) {
				if(cnt2.size()==k&&cnt2.count(nums[R2])==0) break;
				cnt2[nums[R2++]]++;
			}
			while(R1<N&&ok<k) {
				cnt1[nums[R1]]++;
				if(cnt1[nums[R1]]==m) ok++;
				R1++;
			}
			if(ok==k&&R1<=R2) ret+=R2-R1+1;
			cnt2[nums[L]]--;
			cnt1[nums[L]]--;
			if(cnt2[nums[L]]==0) cnt2.erase(nums[L]);
			if(cnt1[nums[L]]==m-1) ok--;
			if(cnt1[nums[L]]==0) cnt1.erase(nums[L]);
			
		}
        return ret;
    }
};


