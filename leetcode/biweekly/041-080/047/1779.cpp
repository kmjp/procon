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
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
		int d=1010101,tar=-1;
		int i;
		FOR(i,points.size()) {
			if(x==points[i][0]||y==points[i][1]) {
				int cd=abs(x-points[i][0])+abs(y-points[i][1]);
				if(cd<d) d=cd,tar=i;
			}
		}
		return tar;
		
        
    }
};

