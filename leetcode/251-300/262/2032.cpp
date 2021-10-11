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
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
		vector<int> V;
		int i;
		FOR(i,101) {
			int x=0;
			x+=count(ALL(nums1),i)>0;
			x+=count(ALL(nums2),i)>0;
			x+=count(ALL(nums3),i)>0;
			if(x>=2) V.push_back(i);
			
			
		}
		return V;
        
    }
};
