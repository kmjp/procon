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

vector<int> V[101010];
vector<int> E[101010];
string S;
int ma;
class Solution {
public:
	int dfs(int cur) {
		V[cur]={0,0};
		FORR(e,E[cur]) {
			int x=dfs(e);
			if(S[cur]!=S[e]) V[cur].push_back(x);
		}
		sort(ALL(V[cur]));
		reverse(ALL(V[cur]));
		ma=max(ma,1+V[cur][0]+V[cur][1]);
		return 1+V[cur][0];
		
	}
    int longestPath(vector<int>& parent, string s) {
		int N=parent.size();
		S=s;
		int i;
		FOR(i,N) E[i].clear();
		FOR(i,N) {
			if(i) E[parent[i]].push_back(i);
		}
		ma=0;
		dfs(0);
        return ma;
    }
};
