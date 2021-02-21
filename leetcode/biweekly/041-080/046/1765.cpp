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

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
		int H=isWater.size();
		int W=isWater[0].size();
		auto R=isWater;
		int y,x;
		queue<int> Q;
		FOR(y,H) FOR(x,W) {
			if(isWater[y][x]==1) {
				R[y][x]=0;
				Q.push(y*1000+x);
			}
			else {
				R[y][x]=101010;
			}
		}
		while(Q.size()) {
			int cy=Q.front()/1000;
			int cx=Q.front()%1000;
			Q.pop();
			int d[4]={0,1,0,-1};
			int i;
			FOR(i,4) {
				int ty=cy+d[i];
				int tx=cx+d[i^1];
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				if(R[ty][tx]>R[cy][cx]+1) {
					R[ty][tx]=R[cy][cx]+1;
					Q.push(ty*1000+tx);
				}
			}
			
		}
		return R;
        
    }
};
