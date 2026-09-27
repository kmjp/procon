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

vector<int> P[3030];
vector<int> cand[3030];

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
		int i;
		FOR(i,k) P[i].clear(),cand[i].clear();
		int cur=0;
		P[0].push_back(0);
		FOR(i,nums.size()) {
			cur=((cur+nums[i])%k+k)%k;
			P[cur].push_back(i+1);
			cand[((2*nums[i]%k)+k)%k].push_back(i+1);
		}
		int ma=0;
		int x,y;
		FOR(x,k) FOR(y,k) {
			
			if(y==0) {
				if(P[x].size()>=2) ma=max(ma,P[x].back()-P[x][0]);
			}
			else {
				if(P[x].empty()) continue;
				if(P[(x+y)%k].empty()) continue;
				int L=P[x][0];
				int R=P[(x+y)%k].back();
				auto it=lower_bound(ALL(cand[y]),L+1);
				if(it!=cand[y].end()&&*it<=R) {
					ma=max(ma,R-L);
				}
			}
		}
		return ma;
        
    }
};
