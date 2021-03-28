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

const ll mo=1000000007;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class Solution {
public:
    int maxNiceDivisors(int primeFactors) {
		
		if(primeFactors<=4) return primeFactors;
		
		
		if(primeFactors%6==1) {
			ll pat=12*modpow(9,(primeFactors-7)/6)%mo;
			return pat;
		}
		else {
			ll pat=modpow(9,primeFactors/6);
			primeFactors%=6;
			if(primeFactors>=1&&primeFactors<=4) pat*=primeFactors;
			if(primeFactors==5) pat*=6;
	        return pat%mo;
	    }
    }
};
