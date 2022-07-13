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

ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll hcomb(ll P_,ll Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);}

class Solution {
public:
    int idealArrays(int n, int maxValue) {
		ll ret=0;
		int i,j;
		for(i=1;i<=maxValue;i++) {
			ll pat=1;
			map<int,int> M;
			int x=i;
			for(j=2;j*j<=x;j++) while(x%j==0) {
				x/=j;
				M[j]++;
			}
			if(x>1) M[x]++;
			
			FORR(a,M) pat=pat*hcomb(n,a.second)%mo;
			ret+=pat;
			
		}
		return ret%mo;
        
    }
};
