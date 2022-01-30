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

ll V[202020];
ll P[202020];
class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
		V[0]=0;
		int N=s.size();
		P[0]=1;
		int i;
		FORR(c,s) c=c-'a'+1;
		FOR(i,N) {
			P[i+1]=P[i]*power%modulo;
		}
		ll S=0;
		for(i=N-k;i<N;i++) {
			S+=s[i]*P[i-(N-k)]%modulo;
		}
		S%=modulo;
		int ma=N;
		if(S==hashValue) ma=N-k;
		
		for(i=N-k-1;i>=0;i--) {
			S=(S*power%modulo-s[i+k]*P[k]%modulo+s[i]+modulo)%modulo;
			if(S==hashValue) ma=i;
		}
		FORR(c,s) c=c+('a'-1);
		return s.substr(ma,k);
    }
};
