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


vector<int> E[1010];
int in[1010];
int vis[1010];
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
		vector<vector<int>> ret(n);
		int i;
		FOR(i,n) E[i].clear(),in[i]=0;
		FORR(v,edges) {
			E[v[0]].push_back(v[1]);
			in[v[1]]++;
		}
		vector<pair<int,int>> NE;
		queue<int> Q;
		FOR(i,n) if(in[i]==0) Q.push(i);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			FORR(e,E[cur]) {
				NE.push_back({cur,e});
				in[e]--;
				if(in[e]==0) Q.push(e);
			}
		}
		
		FOR(i,n) {
			ZERO(vis);
			vis[i]=1;
			FORR(a,NE) if(vis[a.first]==1) {
				if(vis[a.second]==0) {
					ret[a.second].push_back(i);
					vis[a.second]=1;
				}
			}
		}
		return ret;
		
		
        
    }
};