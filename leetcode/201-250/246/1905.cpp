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
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
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
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
		UF<500*500> uf;
        int H=grid1.size();
        int W=grid1[0].size();
        int y,x;
        FOR(y,H) FOR(x,W) {
			if(grid1[y][x]&&grid2[y][x]) grid2[y][x]=2;;
			if(y&&grid2[y][x]&&grid2[y-1][x]) uf(y*W+x,(y-1)*W+x);
			if(x&&grid2[y][x]&&grid2[y][x-1]) uf(y*W+x,y*W+x-1);
		}
		vector<int> C[3];
		C[0].resize(500*500);
		C[1].resize(500*500);
		C[2].resize(500*500);
		FOR(y,H) FOR(x,W) {
			C[grid2[y][x]][uf[y*W+x]]++;
		}
		int ret=0;
		FOR(y,H*W) if(C[2][y]&&C[1][y]==0) ret++;
		return ret;
        
    }
};
