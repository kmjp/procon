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
    int minLength(vector<int>& nums, int k) {
        map<int,int> M;
        ll sum=0;
        int mi=1<<20;
        for(int L=0,R=0;L<nums.size();L++) {
			while(R<nums.size()&&sum<k) {
				M[nums[R]]++;
				if(M[nums[R]]==1) sum+=nums[R];
				R++;
			}
			if(sum>=k) mi=min(mi,R-L);
			M[nums[L]]--;
			if(M[nums[L]]==0) {
				sum-=nums[L];
			}
		}
        
        if(mi==1<<20) mi=-1;
        return mi;
    }
};
