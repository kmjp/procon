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


vector<int> E[10101];
int P[10101];
int S[10101];
int C[10101];

class Solution {
public:
	pair<int,int> dfs(int cur) {
		C[cur]=1;
		FORR(e,E[cur]) {
			auto p=dfs(e);
			S[cur]+=p.first;
			C[cur]+=p.second;
		}
		if(S[cur]==0) C[cur]=0;
		return {S[cur],C[cur]};
	}
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
		int i;
		FOR(i,nodes) E[i].clear();
		FOR(i,nodes) S[i]=value[i];
		FOR(i,nodes) P[i]=parent[i];
		FOR(i,nodes) if(i) E[parent[i]].push_back(i);
        return dfs(0).second;
    }
};
