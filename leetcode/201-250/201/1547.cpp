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


ll C[102][102];

class Solution {
public:
	
    int minCost(int n, vector<int>& cuts) {
		vector<int> V;
		V.push_back(0);
		sort(ALL(cuts));
		FORR(c,cuts) V.push_back(c);
		V.push_back(n);
		int N=cuts.size()+1;
		int i,x,y;
		
		for(int len=2;len<=N;len++) {
			for(x=0;x+len<=N;x++) {
				C[x][x+len]=1LL<<30;
				for(y=x+1;y<x+len;y++) C[x][x+len]=min(C[x][x+len],V[x+len]-V[x]+C[x][y]+C[y][x+len]);
			}
		}
        
        
        return C[0][N];
    }
};
