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




vector<int> V[101010];

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
		int i;
		FOR(i,101010) V[i].clear();
		int y,x;
		FOR(y,nums.size()) {
			FOR(x,nums[y].size()) V[y+x].push_back(nums[y][x]);
		}
		
		vector<int> R;
		FOR(i,101010) {
			reverse(ALL(V[i]));
			FORR(v,V[i]) R.push_back(v);
		}
		return R;
    }
};





