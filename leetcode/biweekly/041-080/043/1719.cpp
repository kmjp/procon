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


unordered_set<int> E[505];

int N;
class Solution {
public:
	int dfs(int root, unordered_set<int>& V) {
		int N=V.size();
		int ret=1;
		vector<pair<int,int>> cand;
		FORR(p,E[root]) {
			if(V.count(p)==0) return 0;
			if(E[p].size()==N) ret=2;
			E[p].erase(root);
			cand.push_back({-(int)E[p].size(),p});
		}
		
		sort(ALL(cand));
		FORR(c,cand) {
			int num=-c.first;
			int v=c.second;
			if(num>=1&&num==E[v].size()) {
				unordered_set<int> NS;
				if(E[v].size()<=V.size()) {
					NS=E[v];
					auto it=NS.begin();
					while(it!=NS.end()) {
						if(V.count(*it)) {
							it++;
						}
						else {
							it=NS.erase(it);
						}
					}
					//FORR(e,E[v]) if(V.count(e)) NS.insert(e);
				}
				else {
					NS=V;
					auto it=NS.begin();
					while(it!=NS.end()) {
						if(E[v].count(*it)) {
							it++;
						}
						else {
							it=NS.erase(it);
						}
					}
					//FORR(e,V) if(E[v].count(e)) NS.insert(e);
				}
				int d=dfs(v,NS);
				if(d==0) return 0;
				if(d==2) ret=2;
			}
		}
		
		return ret;
		
	}
    int checkWays(vector<vector<int>>& pairs) {
		unordered_set<int> V;
		int i;
		FOR(i,501) E[i].clear();
		FORR(p,pairs) {
			V.insert(p[0]);
			V.insert(p[1]);
			E[p[0]].insert(p[1]);
			E[p[1]].insert(p[0]);
		}
		FOR(i,501) if(E[i].size()==V.size()-1) return dfs(i,E[i]);
		return 0;
        
    }
};

