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

int C[101][101];
vector<pair<int,int>> cand;
class Solution {
public:
	
	
	int shortestBridge(vector<vector<int>>& A) {
		int H=A.size(),W=A[0].size();
		ZERO(C);
		
		int i,j,k,x,y;
		int sy,sx;
		FOR(y,H) FOR(x,W) if(A[y][x]) sy=y, sx=x;
		
		cand.clear();
		C[sy][sx]=1;
		queue<pair<int,int>> Q;
		Q.push({sy,sx});
		while(Q.size()) {
			cand.push_back(Q.front());
			sy=Q.front().first;
			sx=Q.front().second;
			Q.pop();
			int d[4]={0,1,0,-1};
			FOR(i,4) {
				int ty=sy+d[i];
				int tx=sx+d[i^1];
				if(tx<0 || tx>=W || ty<0 || ty>=H) continue;
				if(A[ty][tx]==0 || C[ty][tx]) continue;
				C[ty][tx]=1;
				Q.push({ty,tx});
			}
		}
		
		int mi=1010101;
		FOR(y,H) FOR(x,W) if(A[y][x] && C[y][x]==0) {
			FORR(c,cand) mi=min(mi,abs(y-c.first)+abs(x-c.second)-1);
		}
		return mi;
	}
};
