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
ll fact[3030];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class Solution {
public:
    int makeStringSorted(string s) {
		int i,j;
		fact[0]=1;
		FOR(i,3020) fact[i+1]=fact[i]*(i+1)%mo;
		
		
		
		reverse(ALL(s));
		int C[26]={};
		ll ret=0;
		FORR(c,s) {
			c-='a';
			C[c]++;
			FOR(i,c) if(C[i]) {
				C[i]--;
				ll pat=1;
				int sum=0;
				FOR(j,26) {
					sum+=C[j];
					(pat*=fact[C[j]])%=mo;
				}
				pat=fact[sum]*modpow(pat)%mo;
				ret+=pat;
				C[i]++;
			}
		}
		return ret%mo;
		
		
        
    }
};
