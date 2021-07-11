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

vector<pair<int,int>> E[1010];
int cost[1010][1010];

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int N=passingFees.size();
        int i,j;
        FOR(i,N) {
			E[i].clear();
			FOR(j,1010) cost[i][j]=1<<30;
		}
        FORR(e,edges) {
			E[e[0]].push_back({e[1],e[2]});
			E[e[1]].push_back({e[0],e[2]});
		}
		cost[0][0]=passingFees[0];
		int t;
		FOR(t,maxTime) {
			FOR(i,N) if(cost[i][t]<1<<30) {
				cost[i][t+1]=min(cost[i][t+1],cost[i][t]);
				FORR(e,E[i]) if(t+e.second<=maxTime) {
					cost[e.first][t+e.second]=min(cost[e.first][t+e.second],cost[i][t]+passingFees[e.first]);
				}
			}
		}
		int ret=cost[N-1][maxTime];
		if(ret>=1<<30) ret=-1;
		return ret;
    }
};

 