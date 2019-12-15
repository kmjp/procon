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
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int rem=0;
        int x,y;
        FOR(x,intervals.size()) {
			int ok=1;
			FOR(y,intervals.size()) if(x!=y) {
				if(intervals[y][0]<=intervals[x][0] && intervals[x][1]<=intervals[y][1]) ok=0;
			}
			rem+=ok;
		}
		return rem;
    }
};


