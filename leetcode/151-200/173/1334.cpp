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
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int mat[101][101];
        int x,y,z;
        FOR(x,n) FOR(y,n) mat[x][y]=(x==y)?0:1<<20;
        FORR(e,edges) mat[e[0]][e[1]]=mat[e[1]][e[0]]=e[2];
        FOR(z,n) FOR(x,n) FOR(y,n) mat[x][y]=min(mat[x][y],mat[x][z]+mat[z][y]);
        int id=0;
        int num[100]={};
        FOR(x,n) {
			FOR(y,n) num[x]+=mat[x][y]<=distanceThreshold;
			if(num[x]<=num[id]) id=x;
		}
		return id;
    }
};