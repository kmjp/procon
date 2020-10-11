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
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
		vector<int> D(n-1);
		int E[15][15];
		int i,x,y;
		FOR(x,15) FOR(y,15) E[x][y]=(x==y)?0:100;
		FORR(e,edges) {
			e[0]--;
			e[1]--;
			E[e[0]][e[1]]=E[e[1]][e[0]]=1;
		}
		FOR(i,n) FOR(x,n) FOR(y,n) E[x][y]=min(E[x][y],E[x][i]+E[i][y]);
		
		int mask;
		for(mask=1;mask<1<<n;mask++) {
			UF<15> uf;
			int ma=0;
			FORR(e,edges) {
				if(mask&(1<<e[0])) {
					if(mask&(1<<e[1])) {
						uf(e[0],e[1]);
						ma=max(ma,uf.count(e[0]));
					}
				}
			}
			if(ma!=__builtin_popcount(mask)) continue;
			ma=0;
			FOR(y,n) FOR(x,y) if(mask&(1<<x)) if(mask&(1<<y)) ma=max(ma,E[x][y]);
			if(ma==0||ma>99) continue;
			D[ma-1]++;
			
		}
        return D;
    }
};
