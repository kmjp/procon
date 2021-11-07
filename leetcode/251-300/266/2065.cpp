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


vector<pair<int,int>> E[2020];
vector<int> V;
class Solution {
public:
	int ma;
	void dfs(int cur,int d,set<int>& S,int sum) {
		if(cur==0) ma=max(ma,sum);
		FORR(e,E[cur]) if(d>=e.second) {
			if(S.count(e.first)) {
				dfs(e.first,d-e.second,S,sum);
			}
			else {
				S.insert(e.first);
				dfs(e.first,d-e.second,S,sum+V[e.first]);
				S.erase(e.first);
			}
		}
		
	}
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
		V=values;
		int N=values.size();
        int i;
        FOR(i,N) E[i].clear();
        FORR(e,edges) {
			E[e[0]].push_back({e[1],e[2]});
			E[e[1]].push_back({e[0],e[2]});
		}
		ma=0;
		set<int> S={0};
		dfs(0,maxTime,S,V[0]);
		return ma;
        
    }
};
