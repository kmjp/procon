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

int L[20202];
int R[20202];


class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
		int i;
		int N=nums.size();
		FOR(i,nums[k]+1) L[i]=0,R[i]=N-1;
		FOR(i,k+1) L[nums[i]+1]=i+1;
		for(i=N-1;i>=k;i--) R[nums[i]+1]=i-1;
		ll ret=0;
		for(i=1;i<=nums[k];i++) {
			L[i]=max(L[i],L[i-1]);
			R[i]=min(R[i],R[i-1]);
			ret=max(ret,i*(R[i]-L[i]+1LL));
		}
		return ret;
		
        
    }
};
