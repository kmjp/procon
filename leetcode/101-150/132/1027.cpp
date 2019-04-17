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

int L[2020][20101];

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        ZERO(L);
        int N=A.size();
        int ma=0;
        int x,y;
        for(x=N-1;x>=0;x--) {
			for(y=x+1;y<N;y++) {
				int d=A[y]-A[x]+10050;
				L[x][d]=max(L[x][d],1+L[y][d]);
				ma=max(ma,L[x][d]+1);
			}
		}
        return ma;
        
    }
};

