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

vector<pair<int,int>> E[101010][3];
ll D[101010][3];
class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        int i,j;
        FOR(i,n) {
			FOR(j,3) {
				E[i][j].clear();
				D[i][j]=1LL<<60;
			}
		}
		FORR(e,edges) {
			E[e[0]][0].push_back({e[1],e[2]});
			E[e[0]][1].push_back({e[1],e[2]});
			E[e[1]][2].push_back({e[0],e[2]});
		}
		priority_queue<pair<ll,int>> Q;
		D[src1][0]=D[src2][1]=D[dest][2]=0;
		Q.push({0,src1*10});
		Q.push({0,src2*10+1});
		Q.push({0,dest*10+2});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second/10;
			int id=Q.top().second%10;
			Q.pop();
			if(D[cur][id]!=co) continue;
			FORR(e,E[cur][id]) {
				if(D[e.first][id]>co+e.second) {
					D[e.first][id]=co+e.second;
					Q.push({-D[e.first][id],e.first*10+id});
				}
			}
		}
		ll mi=1LL<<60;
		FOR(i,n) {
			mi=min(mi,D[i][0]+D[i][1]+D[i][2]);
		}
		
		if(mi==1LL<<60) mi=-1;
		return mi;
    }
};
