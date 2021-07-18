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

ll from[101010];


class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
		int H=points.size();
		int W=points[0].size();
		ZERO(from);
		int y,x;
		FOR(y,H) {
			FOR(x,W) from[x]+=points[y][x];
			FOR(x,W-1) from[x+1]=max(from[x+1],from[x]-1);
			for(x=W-1;x>0;x--) from[x-1]=max(from[x-1],from[x]-1);
		}
		
		return *max_element(from,from+W);
		
		
        
    }
};
