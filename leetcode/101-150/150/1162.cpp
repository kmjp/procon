
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

    int maxDistance(vector<vector<int>>& G) {
		int H=G.size();
		int W=G[0].size();
		int D[101][101]={};
		int y,x,i;
		FOR(y,H) FOR(x,W) {
			if(G[y][x]==1) D[y][x]=0;
			else D[y][x]=500;
		}
		FOR(i,202) {
			FOR(y,H) FOR(x,W) {
				if(y) D[y][x]=min(D[y][x],D[y-1][x]+1);
				if(y+1<H) D[y][x]=min(D[y][x],D[y+1][x]+1);
				if(x) D[y][x]=min(D[y][x],D[y][x-1]+1);
				if(x+1<W) D[y][x]=min(D[y][x],D[y][x+1]+1);
			}
		}
        
        int ma=-1;
        FOR(y,H) FOR(x,W) if(G[y][x]==0) ma=max(ma,D[y][x]);
        if(ma==500) ma=-1;
        return ma;
        
    }

};

