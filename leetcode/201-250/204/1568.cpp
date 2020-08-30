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
    int minDays(vector<vector<int>>& grid) {
        int H=grid.size();
        int W=grid[0].size();
        
        int mi=2;
        int x,y,ty,tx;
        FOR(y,H) FOR(x,W+1) {
			vector<vector<int>> G=grid;
			if(x<W) G[y][x]=0;
			
			UF<900> uf;
			FOR(ty,H) FOR(tx,W) {
				if(ty&&G[ty][tx]==G[ty-1][tx]) uf(ty*30+tx,(ty-1)*30+tx);
				if(tx&&G[ty][tx]==G[ty][tx-1]) uf(ty*30+tx,(ty-0)*30+tx-1);
			}
			int num=0;
			FOR(ty,H) FOR(tx,W) if(uf[ty*30+tx]==ty*30+tx&&G[ty][tx]) num++;
			if(num!=1) {
				if(x==W) mi=0;
				else mi=1;
			}
		}
        return mi;
    }
};


