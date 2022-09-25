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

int L[101010],R[101010];

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int i;
        int N=nums.size();
        for(i=1;i<N;i++) {
			if(nums[i-1]>=nums[i]) L[i]=L[i-1]+1;
			else L[i]=0;
		}
		R[N-1]=0;
		for(i=N-2;i>=0;i--) {
			if(nums[i+1]>=nums[i]) R[i]=R[i+1]+1;
			else R[i]=0;
		}
		vector<int> V;
		for(i=k;i+k<N;i++) if(L[i-1]>=k-1&&R[i+1]>=k-1) V.push_back(i);
		return V;
    }
};
