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

ll S[101010];

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
		int N=nums.size();
		set<pair<int,int>> T;
		set<int> dead;
		int i;
		dead.insert(0);
		dead.insert(N+1);
		FOR(i,N) {
			S[i+1]=S[i]+nums[i];
			T.insert({nums[i],i+1});
		}
		ll ret=0;
		FORR(v,T) {
			ll a=v.first;
			int cur=v.second;
			auto it=dead.lower_bound(cur);
			int R=*it;
			int L=*--it;
			ret=max(ret,a*(S[R-1]-S[L]));
			
			dead.insert(cur);
		}
        
        return ret%1000000007;
    }
};
