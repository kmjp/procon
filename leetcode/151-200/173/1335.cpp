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

int from[303];
int to[303];


class Solution {
public:
    int minDifficulty(vector<int>& J, int d) {
		int N=J.size();
		int i,x,y;
		FOR(x,N) from[x]=1<<30;
		from[0]=0;
		while(d--) {
			FOR(x,N+1) to[x]=1<<30;
			
			FOR(x,N) {
				int ma=0;
				for(y=x;y<N;y++) {
					ma=max(ma,J[y]);
					to[y+1]=min(to[y+1],from[x]+ma);
				}
			}
			
			swap(from,to);
		}
		
		if(from[N]>=1<<30) from[N]=-1;
		return from[N];
        
    }
};

