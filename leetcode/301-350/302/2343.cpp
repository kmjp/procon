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
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
		vector<int> ret;
		FORR(q,queries) {
			vector<pair<string,int>> V;
			int i;
			FOR(i,nums.size()) {
				V.push_back({nums[i].substr(nums[0].size()-q[1]),i});
			}
			sort(ALL(V));
			ret.push_back(V[q[0]-1].second);
		}
		return ret;
        
    }
};
