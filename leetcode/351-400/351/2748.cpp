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
    int countBeautifulPairs(vector<int>& nums) {
		int ret=0;
		int a,b;
		for(a=0;a<nums.size();a++) {
			for(b=a+1;b<nums.size();b++) {
				int x=nums[a];
				int y=nums[b]%10;
				while(x>=10) x/=10;
				if(__gcd(x,y)==1) ret++;
			}
		}
        return ret;
    }
};
