
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

int D[101][2];

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        int i,j,k;
        FOR(j,n) D[j][0]=D[j][1]=1<<20;
        D[0][0]=D[0][1]=0;
        
        FOR(i,2*n) {
			FORR(e,red_edges) D[e[1]][1]=min(D[e[1]][1],D[e[0]][0]+1);
			FORR(e,blue_edges) D[e[1]][0]=min(D[e[1]][0],D[e[0]][1]+1);
		}
        
        vector<int> V;
        FOR(i,n) {
			int v=min(D[i][0],D[i][1]);
			if(v==1<<20) v=-1;
			V.push_back(v);
		}
		return V;
    }
};

