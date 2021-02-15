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

int C[404][404];
int E[404];

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        ZERO(C);
        ZERO(E);
        FORR(e,edges) {
			e[0]--,e[1]--;
			C[e[0]][e[1]]=C[e[1]][e[0]]=1, E[e[0]]++,E[e[1]]++;
		}
        int mi=1<<20;
        int x,y,z;
        FOR(z,n) FOR(y,z) FOR(x,z) if(C[x][y]&&C[y][z]&&C[z][x]) mi=min(mi,E[x]+E[y]+E[z]-6);
        
        if(mi==1<<20) mi=-1;
        return mi;
        
    }
};
