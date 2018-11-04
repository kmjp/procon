typedef signed long long ll;

#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))

int C[303];

class Solution {
public:
	int minMalwareSpread(vector<vector<int>>& G, vector<int>& initial) {
		int N=G.size();
		int x,y,z,i;
		int mi=101010;
		int be=01;
		sort(ALL(initial));
		FORR(x,initial) {
			int c=0;
			
			ZERO(C);
			queue<int> Q;
			FORR(y,initial) if(x!=y) {
				Q.push(y);
				C[y]=1;
			}
			while(Q.size()) {
				y=Q.front();
				Q.pop();
				c++;
				FOR(i,N) if(G[y][i] && C[i]==0) {
					C[i]=1;
					Q.push(i);
				}
			}
			
			if(c<mi) mi=c,be=x;
			
		}
		return be;
	}
};
