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


int D[101010];
vector<int> E[101010];

class Solution {
public:
	void dfs(int cur,int pre,int d) {
		D[cur]=d;
		FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d+1);
	}

    int minReorder(int n, vector<vector<int>>& connections) {
		
		int i;
		FOR(i,n) E[i].clear();
		FORR(c,connections) {
			E[c[0]].push_back(c[1]);
			E[c[1]].push_back(c[0]);
		}
		dfs(0,0,0);
		
		int ret=0;
		FORR(c,connections) {
			if(D[c[0]]<D[c[1]]) ret++;
		}
        return ret;
    }
};


