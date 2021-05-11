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

vector<int> E[101010];
int in[101010];
vector<int> order;
int C[101010][26];

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
		
		int i;
		int N=colors.size();
		ZERO(in);
		ZERO(C);
		FOR(i,N) E[i].clear();
		FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			in[e[1]]++;
		}
		order.clear();
		queue<int> Q;
		FOR(i,N) if(in[i]==0) {
			Q.push(i);
		}
		int ma=0;
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			C[cur][colors[cur]-'a']++;
			FOR(i,26) ma=max(ma,C[cur][i]);
			
			FORR(e,E[cur]) {
				FOR(i,26) C[e][i]=max(C[e][i],C[cur][i]);
				in[e]--;
				if(in[e]==0) Q.push(e);
			}
		}
		
		
		
        FOR(i,N) if(in[i]) return -1;
        return ma;
    }
};
