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
    long long numberOfSubsequences(vector<int>& nums) {
		ll ret=0;
		int N=nums.size();
		map<pair<int,int>,int> M;
		int a,b,c,d;
		FOR(b,N) {
			for(c=b+2;c<N;c++) {
				int g=__gcd(nums[b],nums[c]);
				ret+=M[{nums[c]/g,nums[b]/g}];
			}
			if(b) {
				FOR(a,b-2) {
					int g=__gcd(nums[b-1],nums[a]);
					M[{nums[a]/g,nums[b-1]/g}]++;
				}
			}
		}
        return ret;
    }
};

