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
    int countLatticePoints(vector<vector<int>>& circles) {
		
		int ret=0;
		int x,y;
		FOR(x,201) FOR(y,201) {
			FORR(c,circles) {
				if((c[0]-x)*(c[0]-x)+(c[1]-y)*(c[1]-y)<=c[2]*c[2]) {
					ret++;
					break;
				}
			}
		}
		return ret;
        
    }
};
