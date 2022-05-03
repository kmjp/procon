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
    int countDistinct(vector<int>& nums, int k, int p) {
		vector<vector<int>> R[202];
		int i,j;
		FOR(i,nums.size()) {
			int ng=0;
			vector<int> V;
			for(j=i;j<nums.size();j++) {
				if(nums[j]%p==0) ng++;
				if(ng>k) break;
				V.push_back(nums[j]);
				R[V.size()].push_back(V);
			}
		}
		
		int ret=0;
		FOR(i,202) if(R[i].size()) {
			ret++;
			sort(ALL(R[i]));
			for(j=1;j<R[i].size();j++) if(R[i][j]!=R[i][j-1]) ret++;
		}
		return ret;
        
    }
};

