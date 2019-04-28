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

vector<int> R,C;
int G[606][606];
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
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
		R.clear();
		C.clear();
		R.push_back(0);
		R.push_back(999999);
		C.push_back(0);
		C.push_back(999999);
		blocked.push_back(source);
		blocked.push_back(target);
		FORR(b,blocked) {
			if(b[0]) R.push_back(b[0]-1);
			R.push_back(b[0]);
			if(b[0]<999999) R.push_back(b[0]+1);
			if(b[1]) C.push_back(b[1]-1);
			C.push_back(b[1]);
			if(b[1]<999999) C.push_back(b[1]+1);
		}
		blocked.pop_back();
		blocked.pop_back();
		sort(ALL(R));
		sort(ALL(C));
		R.erase(unique(ALL(R)),R.end());
		C.erase(unique(ALL(C)),C.end());
		
		ZERO(G);
		FORR(b,blocked) {
			int y=lower_bound(ALL(R),b[0])-R.begin();
			int x=lower_bound(ALL(C),b[1])-C.begin();
			G[y][x]=1;
		}
		int sy=lower_bound(ALL(R),source[0])-R.begin();
		int sx=lower_bound(ALL(C),source[1])-C.begin();
		int ty=lower_bound(ALL(R),target[0])-R.begin();
		int tx=lower_bound(ALL(C),target[1])-C.begin();
		
		uf.reinit();
		int y,x;
		FOR(y,R.size()) FOR(x,C.size()) if(G[y][x]==0) {
			if(y&&G[y-1][x]==0) uf(y*1000+x,y*1000+x-1000);
			if(x&&G[y][x-1]==0) uf(y*1000+x,y*1000+x-1);
		}
		
		return uf[sy*1000+sx]==uf[ty*1000+tx];
		
		
		
    }
};

