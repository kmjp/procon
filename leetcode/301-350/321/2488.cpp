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
    int countSubarrays(vector<int>& nums, int k) {
		map<int,int> L,R;
		int i;
		int N=nums.size();
		FOR(i,N) if(nums[i]==k) break;
		int c=i;
		L[0]++;
		R[0]++;
		int cur=0;
		for(i=c-1;i>=0;i--) {
			if(nums[i]<k) cur--;
			else cur++;
			L[cur]++;
		}
		cur=0;
		for(i=c+1;i<N;i++) {
			if(nums[i]<k) cur--;
			else cur++;
			R[cur]++;
		}
		ll ret=0;
		FORR(v,L) {
			int cur=v.first;
			ll a=v.second;
			ret+=R[-cur]*a;
			ret+=R[-cur+1]*a;
		}
        return ret;
    }
};

