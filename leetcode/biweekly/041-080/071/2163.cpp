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

ll X[303030],Y[303030];

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
		int N=nums.size()/3;
		ll A=0;
		ll B=0;
		multiset<int> S,T,U;
		int i,x;
		FOR(i,N) {
			S.insert(nums[i]);
			A+=nums[i];
		}
		X[N]=A;
		for(i=N;i<2*N;i++) {
			S.insert(nums[i]);
			A+=nums[i];
			auto it=prev(S.end());
			A-=*it;
			S.erase(it);
			X[i+1]=A;
		}
		for(i=3*N-1;i>=2*N;i--) {
			T.insert(nums[i]);
			B+=nums[i];
		}
		Y[2*N]=B;
		ll ret=X[2*N]-Y[2*N];
		for(i=2*N-1;i>=N;i--) {
			T.insert(nums[i]);
			B+=nums[i];
			auto it=T.begin();
			B-=*it;
			T.erase(it);
			Y[i]=B;
			ret=min(ret,X[i]-Y[i]);
		}
		
		
		
        return ret;
    }
};
