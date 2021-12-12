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

int E[101][101];


class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
		int i;
		int N=bombs.size();
		ZERO(E);
		int x,y,k;
		FOR(x,N) {
			FOR(y,N) {
				ll dx=bombs[x][0]-bombs[y][0];
				ll dy=bombs[x][1]-bombs[y][1];
				ll dr=bombs[x][2];
				
				if(dx*dx+dy*dy<=dr*dr) {
					E[x][y]=1;
				}
			}
		}
		FOR(k,N) FOR(x,N) FOR(y,N) E[x][y]|=E[x][k]&E[k][y];
		int ma=0;
		FOR(x,N) {
			int ret=0;
			FOR(y,N) ret+=E[x][y];
			ma=max(ma,ret);
		}
		return ma;
		
        
    }
};
