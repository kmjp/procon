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


unordered_map<int,int> nex[20];
class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
		vector<int> S;
		FORR(a,nums) S.push_back(a);
		sort(ALL(S));
		nex[0].clear();
		FORR(a,nums) {
			auto it=lower_bound(ALL(S),a+maxDiff+1);
			nex[0][a]=*--it;
		}
		int i;
		FOR(i,17) {
			nex[i+1].clear();
			FORR(a,nums) nex[i+1][a]=nex[i][nex[i][a]];
		}
		vector<int> ret;
		FORR(q,queries) {
			int a=nums[q[0]];
			int b=nums[q[1]];
			if(q[0]==q[1]) {
				ret.push_back(0);
				continue;
			}
			
			if(a>b) swap(a,b);
			if(nex[17][a]<b) {
				ret.push_back(-1);
				continue;
			}
			int num=1;
			for(i=16;i>=0;i--) if(nex[i][a]<b) {
				num+=1<<i;
				a=nex[i][a];
			}
			ret.push_back(num);
		}
		return ret;
		
		
        
    }
};
