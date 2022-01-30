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
    vector<int> maxScoreIndices(vector<int>& nums) {
		int C[2][2]={};
		FORR(a,nums) C[1][a]++;
		
		int i,N=nums.size();
		int ma=C[0][0]+C[1][1];
		FOR(i,N) {
			C[0][nums[i]]++;
			C[1][nums[i]]--;
			ma=max(ma,C[0][0]+C[1][1]);
		}
		vector<int> ret;
		if(C[0][0]+C[1][1]==ma) ret.push_back(N);
		for(i=N-1;i>=0;i--) {
			C[0][nums[i]]--;
			C[1][nums[i]]++;
			if(C[0][0]+C[1][1]==ma) ret.push_back(i);
			
		}
		reverse(ALL(ret));
		return ret;
        
    }
};
