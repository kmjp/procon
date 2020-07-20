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

vector<int> E[202020];
int num[202020][26];
string L;
class Solution {
public:
	void dfs(int cur,int pre,vector<int>& ret) {
		int i;
		num[cur][L[cur]-'a']++;
		FORR(e,E[cur]) if(e!=pre) {
			dfs(e,cur,ret);
			FOR(i,26) num[cur][i]+=num[e][i];
		}
		ret[cur]=num[cur][L[cur]-'a'];
		return;
		
	}
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
		vector<int> ret(n);
		L=labels;
		int i;
		FOR(i,n) E[i].clear();
		ZERO(num);
		FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
		}
		dfs(0,0,ret);
		return ret;
    }
};

