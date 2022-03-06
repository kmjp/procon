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
    int mostFrequent(vector<int>& nums, int key) {
		map<int,int> M;
		int i;
		int ma=0;
		FOR(i,nums.size()-1) {
			if(nums[i]==key) {
				M[nums[i+1]]++;
				if(M[nums[i+1]]>M[ma]) {
					ma=nums[i+1];
				}
			}
		}
        return ma;
    }
};
