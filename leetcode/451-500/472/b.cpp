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
    int longestBalanced(vector<int>& nums) {
		int ret=0;
		int a,b;
		FOR(a,nums.size()) {
			set<int> E[2];
			for(b=a;b<nums.size();b++) {
				E[nums[b]%2].insert(nums[b]);
				if(E[0].size()==E[1].size()) ret=max(ret,b-a+1);
			}
		}
        return ret;
    }
};


