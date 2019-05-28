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

int B[202020];

class Solution {
public:
    int maxSatisfied(vector<int>& C, vector<int>& G, int X) {
        ZERO(B);
        int i;
        int sum=0;
        FOR(i,C.size()) {
			B[i+1]=B[i];
			if(G[i]==0) {
				sum+=C[i];
			}
			else {
				B[i+1]+=C[i];
			}
		}
		
		int ma=sum;
		FOR(i,C.size()) if(i+X<=C.size()) {
			ma=max(ma,sum+B[i+X]-B[i]);
		}
		return ma;
		
    }
};

