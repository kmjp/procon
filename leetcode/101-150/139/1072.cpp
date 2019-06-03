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
    int maxEqualRowsAfterFlips(vector<vector<int>>& M) {
        map<vector<int>,int> V;
        FORR(m,M) {
			if(m[0]==0) {
				FORR(v,m) v^=1;
			}
			V[m]++;
		}
		int ma=0;
		FORR(v,V) ma=max(ma,v.second);
		return ma;
    }
};

