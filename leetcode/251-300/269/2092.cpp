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
int S[101010];
int vis[101010];
vector<pair<int,int>> E[101010];
vector<int> E2[101010];

class Solution {
public:
	void dfs(int cur) {
		S[cur]=1;
		vis[cur]=1;
		FORR(e,E2[cur]) if(vis[e]==0) dfs(e);
	}
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        int i;
        ZERO(S);
        S[0]=1;
        S[firstPerson]=1;
        FOR(i,101000) E[i].clear();
        FORR(a,meetings) E[a[2]].push_back({a[0],a[1]});
        FOR(i,101000) {
			set<int> cand;
			FORR(e,E[i]) {
				cand.insert(e.first);
				cand.insert(e.second);
				E2[e.second].push_back(e.first);
				E2[e.first].push_back(e.second);
			}
			FORR(s,cand) if(S[s]==1&&vis[s]==0) dfs(s);
			FORR(s,cand) {
				vis[s]=0;
				E2[s].clear();
			}
		}
		vector<int> R;
		FOR(i,n) if(S[i]) R.push_back(i);
		return R;
		
    }
};