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
    vector<int> sortEvenOdd(vector<int>& nums) {
		vector<int> C[2],D;
		int i;
		FOR(i,nums.size()) C[i%2].push_back(nums[i]);
		sort(ALL(C[0]));
		sort(ALL(C[1]));
		reverse(ALL(C[1]));
		FOR(i,nums.size()) D.push_back(C[i%2][i/2]);
		return D;
        
    }
};
