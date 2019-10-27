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

int D[13][13];
int mi;

class Solution {
public:
	int H,W;
	void dfs(int y,int x,int num) {
		if(num>=mi) return;
		while(D[y][x]) {
			x++;
			if(x==W) y++,x=0;
			if(y==H) {
				mi=num;
				return;
			}
		}
		int l,i,j;
		for(l=1;;l++) {
			if(num>=mi) break;
			if(y+l-1>=H || x+l-1>=W) break;
			if(D[y+l-1][x]) break;
			if(D[y][x+l-1]) break;
			FOR(i,l) D[y+l-1][x+i]=1;
			FOR(i,l) D[y+i][x+l-1]=1;
			dfs(y,x,num+1);
		}
		FOR(i,l-1) FOR(j,l-1) D[y+i][x+j]=0;
	}

    int tilingRectangle(int n, int m) {
		H=n,W=m;
		ZERO(D);
		mi=max(n,m);
		
		dfs(0,0,0);
		return mi;
    }
};
