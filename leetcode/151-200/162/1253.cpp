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
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
		int N=colsum.size();
        vector<vector<int>> V;
        V.push_back(vector<int>(N));
        V.push_back(vector<int>(N));
        int i;
        FOR(i,N) {
			if(colsum[i]==2) {
				colsum[i]=0;
				V[0][i]=V[1][i]=1;
				upper--;
				lower--;
			}
		}
        FOR(i,N) if(colsum[i]==1) {
			if(upper>0) {
				upper--;
				V[0][i]=1;
			}
			else if(lower>0) {
				lower--;
				V[1][i]=1;
			}
			else {
				return {};
			}
		}
		
		if(upper==0 && lower==0) return V;
		else return {};
		
        
    }
};
