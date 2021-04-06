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
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
		vector<int> D;
		int i;
		ll ret=0,sum=0;
		set<int> S;
		FOR(i,nums1.size()) {
			S.insert(nums1[i]);
			sum+=abs(nums1[i]-nums2[i]);
		}
		S.insert(-(1<<20));
		S.insert(1<<20);
		
		ret=sum;
		FOR(i,nums1.size()) {
			auto it=S.lower_bound(nums2[i]);
			ret=min(ret,sum-abs(nums1[i]-nums2[i])+abs(*it-nums2[i]));
			it--;
			ret=min(ret,sum-abs(nums1[i]-nums2[i])+abs(*it-nums2[i]));
		}
		return ret%1000000007;
		
        
    }
};







