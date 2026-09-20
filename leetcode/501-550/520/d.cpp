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
    vector<int> largestPower(vector<int>& nums) {
		vector<int> R(15);
		vector<vector<int>> from,to;
		
		from.push_back(nums);
		
		int b;
		for(b=14;b>=0;b--) {
			to.clear();
			int cnt=1;
			FORR(f,from) {
				if(cnt==0) {
					to.push_back(f);
				}
				else {
					vector<int> ok,ng;
					FORR(n,f) {
						if(n&(1<<b)) {
							ok.push_back(n);
							R[14-b]++;
						}
						else {
							ng.push_back(n);
						}
					}
					if(ok.size()) to.push_back(ok);
					if(ng.size()) {
						to.push_back(ng);
						cnt=0;
					}
				}
			}
			from=to;
		}
		return R;
		
        
    }
};
