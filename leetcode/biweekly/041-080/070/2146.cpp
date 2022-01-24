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

vector<int> D[101010];

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int H=grid.size();
        int W=grid[0].size();
        int y,x;
        FOR(y,H) {
			D[y].clear();
			D[y].resize(W,1<<30);
		}
		vector<vector<int>> V;
		queue<int> Q;
		Q.push(start[0]*W+start[1]);
		D[start[0]][start[1]]=0;
		while(Q.size()) {
			int cy=Q.front()/W;
			int cx=Q.front()%W;
			Q.pop();
			
			if(grid[cy][cx]>=pricing[0]&&grid[cy][cx]<=pricing[1]) {
				V.push_back({D[cy][cx],grid[cy][cx],cy,cx});
			}
			
			int i;
			int d[4]={0,1,0,-1};
			FOR(i,4) {
				int ty=cy+d[i];
				int tx=cx+d[i^1];
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				if(D[ty][tx]<1<<30) continue;
				if(grid[ty][tx]==0) continue;
				D[ty][tx]=D[cy][cx]+1;
				Q.push(ty*W+tx);
			}
		}
		sort(ALL(V));
		if(V.size()>k) V.resize(k);
		vector<vector<int>> R;
		FORR(v,V) R.push_back({v[2],v[3]});
		return R;
		
    }
};

