typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
		set<int> S[101];
			int i;
		FOR(i,nums.size()) S[nums[i]].insert(i);
		
		vector<int> R;
		FORR(q,queries) {
			int ret=101;
			int pre=-1000;
			FOR(i,101) {
				auto it=S[i].lower_bound(q[0]);
				if(it==S[i].end()) continue;
				if(*it>q[1]) continue;
				ret=min(ret,i-pre);
				pre=i;
			}
			
			if(ret==101) ret=-1;
			R.push_back(ret);
		}
		return R;
        
    }
};
