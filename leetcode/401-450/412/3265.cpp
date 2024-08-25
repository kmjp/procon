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
    int countPairs(vector<int>& nums) {
		sort(ALL(nums));
		int ret=0;
		int y,x,s,t;
		FOR(y,nums.size()) FOR(x,y) {
			string a=to_string(nums[y]);
			string b=to_string(nums[x]);
			if(a==b) {
				ret++;
			}
			else {
				FOR(t,a.size()) FOR(s,t) {
					swap(a[s],a[t]);
					string c=a;
					while(c[0]=='0') c=c.substr(1);
					if(c==b) {
						ret++;
						goto out;
					}
					swap(a[s],a[t]);
				}
				out:
				;
			}
		}
        return ret;
    }
};

