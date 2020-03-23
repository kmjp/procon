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
    bool hasValidPath(vector<vector<int>>& G) {
		UF<90000> uf;
		int H=G.size();
		int W=G[0].size();
		int y,x;
		FOR(y,H) FOR(x,W) {
			if(y) {
				if(G[y][x]==2||G[y][x]==5||G[y][x]==6) {
					if(G[y-1][x]==2||G[y-1][x]==3||G[y-1][x]==4) {
						uf(y*300+x,(y-1)*300+x);
					}
				}
			}
			if(x) {
				if(G[y][x]==1||G[y][x]==3||G[y][x]==5) {
					if(G[y][x-1]==1||G[y][x-1]==4||G[y][x-1]==6) {
						uf(y*300+x,y*300+x-1);
					}
				}
			}
			
		}
		return uf[0]==uf[(H-1)*300+W-1];
        
    }
};
