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
    int maximumMinimumPath(vector<vector<int>>& A) {
		int H=A.size();
		int W=A[0].size();
		
		
		vector<pair<int,int>> C;
		int y,x;
		FOR(y,H) FOR(x,W) C.push_back({A[y][x],y*100+x});
		sort(ALL(C));
		reverse(ALL(C));
		UF<10101> uf;
		
		FORR(c,C) {
			y=c.second/100;
			x=c.second%100;
			if(y&&A[y-1][x]>=A[y][x]) uf(y*100+x,(y-1)*100+x);
			if(y+1<H&&A[y+1][x]>=A[y][x]) uf(y*100+x,(y+1)*100+x);
			if(x&&A[y][x-1]>=A[y][x]) uf(y*100+x,y*100+x-1);
			if(x+1<W&&A[y][x+1]>=A[y][x]) uf(y*100+x,y*100+x+1);
			
			if(A[0][0]>=c.first&&A[H-1][W-1]>=c.first && uf[0]==uf[(H-1)*100+(W-1)]) return c.first;
		}
		
		return 0;
		
        
    }
};

