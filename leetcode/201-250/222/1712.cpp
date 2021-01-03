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
    int waysToSplit(vector<int>& nums) {
		vector<ll> S;
		int N=nums.size();
		S.push_back(0);
		FORR(n,nums) S.push_back(S.back()+n);
		ll ret=0;
		for(int i=1;i<N;i++) {
			int L=lower_bound(S.begin()+i+1,S.end()-1,S[i]*2)-S.begin()+1;
			ll v=S[N]-S[i];
			int R=lower_bound(S.begin()+i+1,S.end(),S[i]+v/2+1)-S.begin()+1;
			R=min(R,N+1);
			if(R>L) ret+=R-L;
			//cout<<i<<" "<<L<<" "<<R<<" "<<ret<<endl;
			
		}
		
		
		return ret%1000000007;
        
    }
};
