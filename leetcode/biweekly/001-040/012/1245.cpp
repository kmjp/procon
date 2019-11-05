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

int N;
vector<int> E[10101];
int ma=0;

class Solution {
public:
	int dfs(int cur,int pre) {
		vector<int> V;
		V.push_back(0);
		V.push_back(0);
		FORR(e,E[cur]) if(e!=pre) V.push_back(dfs(e,cur)+1);
		sort(ALL(V));
		reverse(ALL(V));
		ma=max(ma,{V[0]+V[1]});
		return V[0];
	}
    int treeDiameter(vector<vector<int>>& edges) {
		
		ma=0;
		int i;
		FOR(i,10100) E[i].clear();
		FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
		}
        dfs(0,0);
        return ma;
    }
};

 