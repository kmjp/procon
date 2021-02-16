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
    int minimumDeviation(vector<int>& nums) {
		set<ll> V;
		FORR(v,nums) {
			if(v%2==0) V.insert(v);
			else V.insert(v*2);
		}
		
		ll ret=*V.rbegin()-*V.begin();
		while(1) {
			ll a=*V.rbegin();
			V.erase(a);
			if(a%2==1) break;
			V.insert(a/2);
			
			ret=min(ret,*V.rbegin()-*V.begin());
			
		}
        return ret;
    }
};