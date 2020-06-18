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



int P[101010][20];
int D[101010];

class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
		int i,j;
		for(i=1;i<n;i++) {
			D[i]=D[parent[i]]+1;
			P[i][0]=parent[i];
		}
		FOR(j,19) FOR(i,n) P[i][j+1]=P[P[i][j]][j];
    }
    
    int getKthAncestor(int node, int k) {
		if(D[node]<k) return -1;
		int i;
		for(i=17;i>=0;i--) if(k&(1<<i)) node=P[node][i];
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */



