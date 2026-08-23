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

const int DI=350;
vector<pair<int,int>> ev[DI];

class Solution {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
		int N=nums.size();
		int i;
		FOR(i,DI) ev[i].clear();
		vector<bool> ret;
		FOR(i,queries.size()) {
			ret.push_back(0);
			ev[queries[i][0]/DI].push_back({queries[i][1],i});
		}
		
		FOR(i,DI) if(ev[i].size()) {
			sort(ALL(ev[i]));
			int CL=i*DI,CR=CL;
			map<int,int> cnt;
			int ne=0;
			FORR2(TR,e,ev[i]) {
				TR++;
				int TL=queries[e][0];
				while(CR<TR) {
					cnt[nums[CR]]++;
					if(cnt[nums[CR]]%2) ne++;
					else ne--;
					CR++;
				}
				while(TL<CL) {
					CL--;
					cnt[nums[CL]]++;
					if(cnt[nums[CL]]%2) ne++;
					else ne--;
				}
				while(CL<TL) {
					cnt[nums[CL]]--;
					if(cnt[nums[CL]]%2) ne++;
					else ne--;
					if(cnt[nums[CL]]==0) cnt.erase(nums[CL]);
					CL++;
				}
				if(cnt.size()==k&&ne==0) ret[e]=1;
				
			}
		}
		return ret;
        
    }
};
