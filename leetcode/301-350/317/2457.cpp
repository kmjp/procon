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
	ll F(ll n) {
		ll a=0;
		while(n) a+=n%10, n/=10;
		return a;
	}
    long long makeIntegerBeautiful(long long n, int target) {
		ll p10=1;
		ll x=0;
		while(1) {
			cout<<n<<" "<<x<<" "<<p10<<endl;
			if(F(n)<=target) return x;
			ll a=n/p10%10;
			if(a) {
				x+=(10-a)*p10;
				n+=(10-a)*p10;
			}
			p10*=10;
		}
		return 0;
        
    }
};



