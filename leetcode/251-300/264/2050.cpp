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

ll D[505050];
vector<int> E[505050];
int in[505050];

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
		int i;
		FOR(i,n) D[i]=0,in[i]=0,E[i].clear();
		FORR(a,relations) E[a[0]-1].push_back(a[1]-1),in[a[1]-1]++;
		priority_queue<pair<ll,int>> Q;
		ll ma=0;
		FOR(i,n) if(in[i]==0) {
			D[i]=time[i];
			Q.push({-D[i],i});
		}
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(D[cur]!=co) continue;
			ma=max(ma,co);
			FORR(e,E[cur]) {
				D[e]=max(D[e],co+time[e]);
				in[e]--;
				if(in[e]==0) {
					Q.push({-D[e],e});
				}
			}
			
		}
		return ma;
        
    }
};
