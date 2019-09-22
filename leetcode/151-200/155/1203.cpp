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

vector<int> G[60606];
vector<int> GE[60606];
int inG[60606];
vector<int> VE[60606];
int inV[60606];

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
		FORR(g,group) if(g==-1) g=m++;
        int i;
        ZERO(inG);
        ZERO(inV);
        FOR(i,60600) G[i].clear(), GE[i].clear(), VE[i].clear();
        FOR(i,n) G[group[i]].push_back(i);
        FOR(i,n) {
			FORR(b,beforeItems[i]) {
				if(group[i]==group[b]) {
					VE[b].push_back(i);
					inV[i]++;
				}
				else {
					GE[group[b]].push_back(group[i]);
					inG[group[i]]++;
				}
			}
		}
		queue<int> Q;
		vector<int> R;
		FOR(i,m) if(inG[i]==0) Q.push(i);
		
		while(Q.size()) {
			int g=Q.front();
			Q.pop();
			
			queue<int> Q2;
			FORR(v,G[g]) if(inV[v]==0) Q2.push(v);
			int lef=G[g].size();
			while(Q2.size()) {
				int v=Q2.front();
				Q2.pop();
				lef--;
				R.push_back(v);
				FORR(v2,VE[v]) {
					inV[v2]--;
					if(inV[v2]==0) Q2.push(v2);
				}
			}
			if(lef) return {};
			
			FORR(e,GE[g]) {
				inG[e]--;
				if(inG[e]==0) Q.push(e);
			}
		}
		
		if(R.size()!=n) return {};
		return R;
		
    }
};
