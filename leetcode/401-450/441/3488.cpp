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

set<int> S[1<<20];
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
		int i,N=nums.size();
		FOR(i,N) {
			S[nums[i]].insert(i);
			S[nums[i]].insert(N+i);
			S[nums[i]].insert(2*N+i);
		}
		vector<int> R;
		FORR(a,queries) {
			auto it=S[nums[a]].find(N+a);
			int mi=min(*it-*prev(it),*next(it)-*it);
			if(mi==N) mi=-1;
			R.push_back(mi);
		}
		
		
		FOR(i,N) S[nums[i]].clear();
        return R;
        
    }
};

