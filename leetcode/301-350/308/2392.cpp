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

vector<int> E[2][404];
int in[2][404];
int R[2][404];

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
		
		int i,j;
		FOR(i,k+1) E[0][i].clear(),E[1][i].clear();
		ZERO(in);
		FORR(a,rowConditions) E[0][a[0]-1].push_back(a[1]-1),in[0][a[1]-1]++;
		FORR(a,colConditions) E[1][a[0]-1].push_back(a[1]-1),in[1][a[1]-1]++;
		vector<int> D[2];
		FOR(i,2) {
			queue<int> Q;
			FOR(j,k) if(in[i][j]==0) Q.push(j);
			while(Q.size()) {
				int cur=Q.front();
				Q.pop();
				R[i][cur]=D[i].size();
				D[i].push_back(cur);
				
				FORR(e,E[i][cur]) {
					in[i][e]--;
					if(in[i][e]==0) Q.push(e);
				}
			}
			if(D[i].size()!=k) return {};
		}
		vector<vector<int>> ret(k);
		FOR(i,k) ret[i].resize(k);
		FOR(i,k) ret[R[0][i]][R[1][i]]=i+1;
		return ret;
        
    }
};
