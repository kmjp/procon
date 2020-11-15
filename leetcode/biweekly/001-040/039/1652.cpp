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
    vector<int> decrypt(vector<int>& code, int k) {
        int N=code.size();
        vector<int> V(N,0);
        int i,j;
        FOR(i,N) {
			if(k>0) {
				FOR(j,k) V[i]+=code[(i+j+1)%N];
			}
			else {
				FOR(j,-k) V[i]+=code[(i+N-(j+1))%N];
			}
		}
		return V;
    }
};
