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

int ma=0;
int H,W;
int from[243][7][7];
int to[243][7][7];
int p3[8];

class Solution {
public:
    int getMaxGridHappiness(int H, int W, int introvertsCount, int extrovertsCount) {
		memset(from,-0x3f,sizeof(from));
		from[0][introvertsCount][extrovertsCount]=0;
		p3[0]=1;
		int i,y,x,a,b,mask;
		FOR(i,7) p3[i+1]=p3[i]*3;
		
		while(H--) {
			FOR(x,W) {
				memset(to,-0x3f,sizeof(to));
				
				FOR(mask,p3[W]) FOR(a,7) FOR(b,7) if(from[mask][a][b]>=-(1<<20)) {
					int v=from[mask][a][b];
					int up=(mask/p3[x])%3;
					int lef=(x==0)?0:(mask/p3[x-1]%3);
					int mask2=mask-up*p3[x];
					
					//none
					to[mask2][a][b]=max(to[mask2][a][b],v);
					if(a) {
						int sc=120;
						if(up==1) sc-=60;
						if(up==2) sc-=10;
						if(lef==1) sc-=60;
						if(lef==2) sc-=10;
						
						to[mask2+p3[x]][a-1][b]=max(to[mask2+p3[x]][a-1][b],v+sc);
					}
					if(b) {
						int sc=40;
						if(up==1) sc-=10;
						if(up==2) sc+=40;
						if(lef==1) sc-=10;
						if(lef==2) sc+=40;
						
						to[mask2+2*p3[x]][a][b-1]=max(to[mask2+2*p3[x]][a][b-1],v+sc);
					}
					
					
				}
				
				swap(from,to);
			}
		}
		
		int ma=0;
		FOR(x,7) FOR(y,7) FOR(mask,p3[W]) ma=max(ma,from[mask][x][y]);
        
        return ma;
        
    }
};
