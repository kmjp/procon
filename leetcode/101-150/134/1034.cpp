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
UF<1010101> uf;

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& G, int r0, int c0, int color) {
        int H=G.size();
        int W=G[0].size();
        int y,x;
        uf.reinit();
        FOR(y,H) FOR(x,W) {
			if(y&&G[y][x]==G[y-1][x]) uf(y*1000+x,(y-1)*1000+x);
			if(x&&G[y][x]==G[y][x-1]) uf(y*1000+x,y*1000+x-1);
		}
        
        FOR(y,H) FOR(x,W) if(uf[y*1000+x]==uf[r0*1000+c0]) {
			if(y==0 || y==H-1 || x==0 || x==W-1) {
				G[y][x]=color;
			}
			else {
				if(uf[y*1000+x]!=uf[y*1000+x+1]) G[y][x]=color;
				if(uf[y*1000+x]!=uf[y*1000+x-1]) G[y][x]=color;
				if(uf[y*1000+x]!=uf[y*1000+x+1000]) G[y][x]=color;
				if(uf[y*1000+x]!=uf[y*1000+x-1000]) G[y][x]=color;
			}
		}
        return G;
    }
};

