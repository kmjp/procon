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

template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
int ng[10000];

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
		int H=grid.size();
		int W=grid[0].size();
		UF<10000> uf;
		int y,x;
		FOR(y,H) FOR(x,W) if(grid[y][x]==0) {
			if(y&&grid[y-1][x]==0) uf(y*100+x,y*100+x-100);
			if(x&&grid[y][x-1]==0) uf(y*100+x,y*100+x-1);
		}
		ZERO(ng);
		FOR(y,H) ng[uf[y*100+0]]=ng[uf[y*100+W-1]]=1;
		FOR(x,W) ng[uf[0*100+x]]=ng[uf[(H-1)*100+x]]=1;
		
		int ret=0;
		FOR(y,H) FOR(x,W) if(grid[y][x]==0 && uf[y*100+x]==y*100+x && ng[uf[y*100+x]]==0) ret++;
		return ret;
		
        
    }
};
