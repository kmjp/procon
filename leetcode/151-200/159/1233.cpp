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
    bool checkStraightLine(vector<vector<int>>& C) {
        sort(ALL(C));
        int dx=C[1][0]-C[0][0];
        int dy=C[1][1]-C[0][1];
        
        if(dx==0) {
			FORR(c,C) if(c[0]!=C[0][0]) return 0;
			return 1;
		}
        if(dy==0) {
			FORR(c,C) if(c[1]!=C[0][1]) return 0;
			return 1;
		}
		int i;
		FOR(i,C.size()-1) {
			if((C[i+1][1]-C[i][1])*dx!=(C[i+1][0]-C[i][0])*dy) return 0;
		}
			return 1;
		
        
    }
};

