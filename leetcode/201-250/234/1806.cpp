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
    int reinitializePermutation(int n) {
		int P[1010],Q[1010];
		int i;
		FOR(i,n) P[i]=i;
		for(int x=1;;x++) {
			FOR(i,n) Q[i]=P[i];
			int ok=1;
			FOR(i,n) {
				if(i%2==0) P[i]=Q[i/2];
				else P[i]=Q[n/2+(i-1)/2];
				if(P[i]!=i)ok=0;
			}
			if(ok) return x;
			
		}
        return -1;
    }
};
