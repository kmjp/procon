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

vector<pair<int,double>> E[101010];
double P[101010];

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
		int i;
		FOR(i,n) E[i].clear(),P[i]=0;
		FOR(i,edges.size()) {
			E[edges[i][0]].push_back({edges[i][1],succProb[i]});
			E[edges[i][1]].push_back({edges[i][0],succProb[i]});
		}
		P[start]=1;
		priority_queue<pair<double,int>> Q;
		Q.push({1,start});
		while(Q.size()) {
			double co=Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(P[cur]!=co) continue;
			if(cur==end) return co;
			FORR(e,E[cur]) if(P[e.first]<co*e.second) {
				P[e.first]=co*e.second;
				Q.push({P[e.first],e.first});
			}
			
		}
        return 0;
    }
};

