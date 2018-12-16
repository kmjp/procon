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
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<30*30*4> uf;

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
		int H=grid.size();
		int W=grid[0].size();
		uf.reinit();
		int y,x,i;
		FOR(y,H) FOR(x,W) {
			if(x) uf((y*W+x)*4+1,(y*W+x-1)*4+2);
			if(y) uf((y*W+x)*4+0,((y-1)*W+x)*4+3);
			if(grid[y][x]==' ' || grid[y][x]=='/') {
				uf((y*W+x)*4+0,(y*W+x)*4+1);
				uf((y*W+x)*4+2,(y*W+x)*4+3);
			}
			if(grid[y][x]==' ' || grid[y][x]=='\\') {
				uf((y*W+x)*4+0,(y*W+x)*4+2);
				uf((y*W+x)*4+1,(y*W+x)*4+3);
			}
		}
		
		int ret=0;
		FOR(i,4*H*W) if(uf[i]==i) ret++;
		return ret;
		
        
    }
};
