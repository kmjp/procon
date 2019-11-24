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

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
		UF<250*250> uf;
		int H=grid.size();
		int W=grid[0].size();
		int x,y,x2,y2;
		FOR(y,H) FOR(x,W) if(grid[y][x]) {
			FOR(x2,W) if(grid[y][x2]) uf(y*250+x,y*250+x2);
			FOR(y2,H) if(grid[y2][x]) uf(y*250+x,y2*250+x);
		}
		int num=0;
		FOR(y,H) FOR(x,W) if(grid[y][x] && uf[y*250+x]==y*250+x && uf.count(y*250+x)>1) {
			num+=uf.count(y*250+x);
		}
		return num;
        
    }
};


