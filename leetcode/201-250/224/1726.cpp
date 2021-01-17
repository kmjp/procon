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
    int tupleSameProduct(vector<int>& nums) {
		map<int,int> M;
		FORR(a,nums) FORR(b,nums) if(a<b) M[a*b]++;
		ll ret=0;
		FORR(m,M) {
			ll a=m.second;
			ret+=a*(a-1)/2;
		}
		return ret*8;
        
    }
};
