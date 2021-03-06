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
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ret=0;
        int i;
        FOR(i,points.size()-1) {
			ret+=max(abs(points[i][0]-points[i+1][0]),abs(points[i][1]-points[i+1][1]));
		}
		return ret;
        
    }
};
