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
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
		map<ll,ll> A,B;
		int i,j;
		FOR(i,nums1.size()) {
			ll a=nums1[i];
			A[a*a]++;
			FOR(j,i) {
				ll b=nums1[j];
				B[a*b]++;
			}
		}
		ll ret=0;
		FOR(i,nums2.size()) {
			ll a=nums2[i];
			ret+=B[a*a];
			FOR(j,i) {
				ll b=nums2[j];
				ret+=A[a*b];
			}
		}
		return ret;
        
    }
};

