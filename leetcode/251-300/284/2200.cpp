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
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
		set<int> S;
		int i,j;
		FOR(i,nums.size()) if(nums[i]==key) {
			for(j=i-k;j<=i+k;j++) {
				if(j>=0&&j<nums.size()) S.insert(j);
			}
		}
        vector<int> R;
        FORR(s,S) R.push_back(s);
        return R;
    }
};
