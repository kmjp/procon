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
    int minMoves(vector<int>& nums, int k) {
		vector<ll> S,V;
		S.push_back(0);
		int i;
		FOR(i,nums.size()) if(nums[i]==1) {
			V.push_back(i-V.size());
			S.push_back(S.back()+V.back());
		}
		ll mi=1LL<<60;
		FOR(i,V.size()) if(i>=k-1) {
			int j=i-(k-1);
			int m=(i+j)/2;
			ll ret=(S[i+1]-S[m+1])-1LL*V[m]*(i-m);
			ret+=1LL*V[m]*(m-j)-(S[m]-S[j]);
			mi=min(mi,ret);
		}
		return mi;
		
        
    }
};
