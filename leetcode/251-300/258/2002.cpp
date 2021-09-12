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

int P[1<<12];
class Solution {
public:
    int maxProduct(string s) {
		int i,j,mask,N=s.size();
		FOR(mask,1<<N) {
			P[mask]=0;
			string T;
			FOR(i,N) if(mask&(1<<i)) T+=s[i];
			int ok=0;
			FOR(i,T.size()) if(T[i]!=T[T.size()-1-i]) break;
			if(i==T.size()) P[mask]=T.size();
		}
		ll ma=0;
		FOR(mask,1<<N) if(P[mask]) {
			int sm=((1<<N)-1)^mask;
			for(int a=sm;a>=0;a--) {
				a&=sm;
				ma=max(ma,(ll)P[mask]*P[a]);
			}
		}
		
        return ma;
    }
};
