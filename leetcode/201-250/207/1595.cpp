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




ll from[1<<12];
ll to[1<<12];

class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
		int N=cost.size();
		int M=cost[0].size();
		int i;
		FOR(i,1<<12) from[i]=1<<30;
		from[0]=0;
		
		int x,y,mask,mask2;
		FOR(x,N) {
			FOR(y,1<<12) to[y]=1<<30;
			FOR(y,M) {
				FOR(mask,1<<M) to[mask|(1<<y)]=min(to[mask|(1<<y)],from[mask]+cost[x][y]);
			}
			for(mask=1;mask<1<<M;mask++) {
				int sc=0;
				FOR(y,M) if(mask&(1<<y)) sc+=cost[x][y];
				int lef=((1<<M)-1)^mask;
				for(int mask2=lef; mask2>0; mask2--) {
					mask2&=lef;
					to[mask|mask2]=min(to[mask|mask2],from[mask2]+sc);
				}
			}
			swap(from,to);
		}
		return from[(1<<M)-1];
        
    }
};
