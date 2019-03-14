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
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int N=A.size();
        int mi=1<<20;
        int i,j,k;
        FOR(j,2) {
			for(i=1;i<=6;i++) {
				int num=0;
				FOR(k,N) {
					if(A[k]==i) continue;
					if(B[k]==i) num++;
					else num=1<<20;
				}
				
				mi=min(mi,num);
			}
			swap(A,B);
		}
        if(mi==1<<20) mi=-1;
        return mi;
    }
};
