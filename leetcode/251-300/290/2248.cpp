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
    vector<int> intersection(vector<vector<int>>& nums) {
		int C[1010]={};
		FORR(n,nums) {
			FORR(a,n) C[a]++;
		}
		vector<int> R;
		int i;
		FOR(i,1005) if(C[i]==nums.size()) R.push_back(i);
		return R;
        
    }
};
