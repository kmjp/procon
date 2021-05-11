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
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
		int ma=0;
		int i,j=-1;
		FOR(i,nums1.size()) {
			j=max(j,i);
			while(j+1<nums2.size()&&nums1[i]<=nums2[j+1]) j++;
			ma=max(ma,j-i);
		}
		return ma;
    }
};
