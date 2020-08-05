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


int live[202];

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
		int N=grid.size();
		int i,j,x,y,z;
		FOR(x,N) live[x]=1;
		int step=0;
		FOR(i,N) {
			FOR(y,N) {
				if(live[y]==0) continue;
				int ok=1;
				for(x=i+1;x<N;x++) if(grid[y][x]) ok=0;
				
				if(ok) break;
				
				step++;
			}
			cout<<i<<" "<<y<<" "<<step<<endl;
			if(y==N) return -1;
			live[y]=0;
		}
		return step;
		
		
        
    }
};

