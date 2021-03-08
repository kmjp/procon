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

vector<pair<int,int>> E[20202];
ll D[20202];
ll pat[20202];
const ll mo=1000000007;

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        int i;
        FOR(i,n) {
			E[i].clear();
			D[i]=1LL<<40;
			pat[i]=0;
		}
		pat[0]=1;
        FORR(e,edges) {
			E[e[0]-1].push_back({e[1]-1,e[2]});
			E[e[1]-1].push_back({e[0]-1,e[2]});
		}
		D[n-1]=0;
		priority_queue<pair<ll,int>> Q,V;
		Q.push({0,n-1});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(D[cur]!=co) continue;
			V.push({D[cur],cur});
			FORR(e,E[cur]) if(D[e.first]>co+e.second) {
				D[e.first]=co+e.second;
				Q.push({-D[e.first],e.first});
			}
		}
		while(V.size()) {
			int cur=V.top().second;
			V.pop();
			FORR(e,E[cur]) if(D[e.first]<D[cur]) (pat[e.first]+=pat[cur])%=mo;
			
		}
		return pat[n-1];
		
    }
};
