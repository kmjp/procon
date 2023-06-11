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
    int sumDistance(vector<int>& nums, string s, int d) {
		vector<int> V;
		int i;
		FOR(i,nums.size()) {
			if(s[i]=='L') V.push_back(nums[i]-d);
			else V.push_back(nums[i]+d);
		}
		sort(ALL(V));
		ll ret=0;
		ll sum=0;
		FOR(i,nums.size()) {
			ret+=(1LL*V[i]*i-sum)%1000000007;
			sum+=V[i];
		}
		return ret%1000000007;
        
    }
};
